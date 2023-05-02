#include "pid/odom_cul.h"
#include "pid/wheel_vel.h"
#include <cmath>
//从轮式编码器发布里程计信息
using namespace std;

//   const double WHEEL_RADIUS = 0.75; //常量要大写,车轮半径
//   const double VEHICLE_WIDTH = 1.5; //车宽
//   const double lf = 1.500; //前车长
//   const double lr = 1.467; //后车长
// 设置履带车辆的宽度和长度 
    const double WHEEL_RADIUS = 0.078; //车轮半径0.078
    const double ROBOT_RADIUS = 0.2095; //车辆半径
    const double ROBOT_LENGTH = 1.096;//车辆长1.096m

    //协方差pose和twist协方差
    boost::array<double, 36> odom_pose_covariance = {
	{1e-9, 0, 0, 0, 0, 0, 
	0, 1e-3, 1e-9, 0, 0, 0, 
	0, 0, 1e6, 0, 0, 0,
	0, 0, 0, 1e6, 0, 0, 
	0, 0, 0, 0, 1e6, 0, 
	0, 0, 0, 0, 0, 1e-9}};
    boost::array<double, 36> odom_twist_covariance = {
	{1e-9, 0, 0, 0, 0, 0, 
	0, 1e-3, 1e-9, 0, 0, 0, 
	0, 0, 1e6, 0, 0, 0, 
	0, 0, 0, 1e6, 0, 0, 
	0, 0, 0, 0, 1e6, 0, 
	0, 0, 0, 0, 0, 1e-9}};


    Odomcul::Odomcul(ros::NodeHandle _n)
	{
		_nh = _n;
		ros::Time::init();
		current_time_ = ros::Time::now(); //当前时间
		last_time_ = ros::Time::now(); //上一时刻时间

		// dynamic reconfiguration
		dynamic_reconfigure::Server<pid::PidConfig> config_server;
		dynamic_reconfigure::Server<pid::PidConfig>::CallbackType f;
		f = boost::bind(&Odomcul::reconfigureCallback, this, _1, _2);
		config_server.setCallback(f);
		cout<<"dynamic"<<endl;

		//设置里程计发布者
	    // geometry_msgs::Quaternion odom_quat;//里程计四元数
	    // geometry_msgs::Pose Model_pose; //里程计消息既有Pose又有twist
	    // geometry_msgs::Twist Model_twist; //
        // ros::NodeHandle _nh;
        // ros::Publisher pub_odom;

		pub_odom = _nh.advertise<nav_msgs::Odometry>("odom", 20);		
		Model_pose.position.x    = 0;
		Model_pose.position.y    = 0;
		Model_pose.position.z    = 0;
		Model_pose.orientation.x = 0;
		Model_pose.orientation.y = 0;
		Model_pose.orientation.z = 0;
		Model_pose.orientation.w = 1;//q = (1, 0, 0, 0)
		Model_twist.linear.x     = 0;
		Model_twist.linear.y     = 0;
		Model_twist.linear.z     = 0;

		//通过gazebo/model来获得的里程计消息(类似与通过/gazebo/linkstates订阅里程计消息)
		ros::Subscriber gazebo_model_states =_nh.subscribe<gazebo_msgs::ModelStates>("/gazebo/model_states",20, boost::bind(&Odomcul::cmdCallback, this, _1));
		ROS_INFO("simulate state is true");
		//订阅wheel_vel
		ros::Subscriber wheel_vel = _nh.subscribe<pid::wheel_vel>("wheel_v",20, boost::bind(&Odomcul::velCallback, this, _1));//订阅发布的轮速
		ROS_INFO("simulate state is false");

		while (ros::ok())
		{
		ros::spinOnce();

		// Add a small sleep to avoid 100% CPU usage
		ros::Duration(0.02).sleep();
		}
    }

void Odomcul::reconfigureCallback(pid::PidConfig& config, uint32_t lever)
{
    slip_n = config.slip_n;
    cout<<"新设置的n值："<<slip_n<<endl;
} 

//通过modelstates获取机器人的Pose和Twist
void Odomcul::cmdCallback(const gazebo_msgs::ModelStates::ConstPtr &msg)
{

	int modelCount = msg->name.size(); //模型里面有多少link(有5个link)

	for(int modelind=0; modelind<modelCount; ++modelind)
	{
	    if(msg->name[modelind]=="xbot-u") //获取model的名字
		{
			Model_pose  = msg->pose[modelind]; //机器人
			//四元数转欧拉角
			//tf::Quaternion quat;
			//tf::quaternionMsgToTF(Model_pose.pose.orientation,quat);
			//double roll, pitch, yaw;
			//tf::Matrix3x3(quat).getRPY(roll,pitch,yaw);
	    	// geometry_msgs::Twist Model_twist; //
			Model_twist = msg->twist[modelind];//name = xbot-u的twist
			double dx =Model_twist.linear.x; //得到模型的x,y方向的线速度
			double dy=Model_twist.linear.y;
			Model_twist.linear.x = sqrt(dx*dx+dy*dy); //x和y的合速度就是总的线速度大小，用于计算2轮中心的转速
			Model_twist.linear.y = 0; 
			
			publishOdom();
	    }
	}
    }

/// @brief 
void Odomcul::velCallback(const pid::wheel_vel::ConstPtr &msg)
{
	//vel_left,vel_right为左右轮的速度
    vel_left = -msg->left_vel.data; //此处的wheel_vel = left_vel.data + right_vel.data和servo_commands中一致，得到了在gazebo中的速度
    vel_right= -msg->right_vel.data;
    encodercul();
}

 bool Odomcul::encodercul(){ //编码器计算
 	//轮子的角速度转换成线速度
	vel_left = vel_left*WHEEL_RADIUS;
	vel_right= vel_right*WHEEL_RADIUS;
	//积分里程计信息
	vx_ = (vel_right+vel_left)/2;//向前的速度 v = (vl + vr) / 2
	vth_= (vel_right-vel_left)/(ROBOT_RADIUS*2); //转弯的角速度 

	/**
	 * @brief 差速模型的计算
	 * v = (vr + vl) / 2
	 * w = (vr - vl) / 
	 * r = v / w
	 * @note 请注意在这里：vx = v(vx就是前进的速度), vy = 0, 
	 * @attention :位置更新
	 * [x(t + 1) = x(t) + vcos(th) * dt
	 *  y(t + 1) = y(t) + vsin(th) * dt
	 *  th(t + 1) = th(t) + w * dt ]
	 */
	Model_twist.linear.x=vx_*cos(th_);//实际上vy  = 0, vx_ = v, vy不需要用到
	Model_twist.linear.y=vx_*sin(th_);
	Model_twist.angular.z=vth_;//转向后的w

	current_time_ = ros::Time::now();
	cout<<"current_time"<<current_time_<<endl;
	cout<<"last_time"<<last_time_<<endl;
	double dt = (current_time_ -last_time_).toSec();
	double delta_x =(vx_*cos(th_))*dt;//x(t + 1) - x(t) = delta_x
	double delta_y =(vx_*sin(th_))*dt; //y(t + 1) - y(t) = delta_y
	double delta_th =vth_*dt; //w*dt

	x_ = x_ + delta_x; //计算最终的的运动状态
	y_ = y_ + delta_y;
	th_= th_ +delta_th;
	if (th_>6.283185307){//2PI,(-2PI, 2PI)
		th_=th_-6.283185307;
	}
	if (th_<-6.283185307){
		th_=th_+6.283185307;
	}
	last_time_= current_time_; //更新时间
	Model_pose.orientation = tf::createQuaternionMsgFromYaw(th_); //其中rp = 0, y != 0从欧拉角构造四元数
	//odom_quat = tf::createQuaternionMsgFromYaw(th_);
	Model_pose.position.x = x_; 
	Model_pose.position.y = y_;
	Model_pose.position.z = 0.0;
	
	//发布消息
	publishOdom();
	return true;
 }

 bool Odomcul::publishOdom(){
	//里程计的发布，需要tf(R, t) + Odometry(Pose(position, orientation), Twist(linear, angular))
	current_time_=ros::Time::now();
	//发布TF
	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.stamp = current_time_;
	odom_trans.header.frame_id ="odom";
	odom_trans.child_frame_id = "base_footprint";

	odom_trans.transform.translation.x = Model_pose.position.x;
	odom_trans.transform.translation.y = Model_pose.position.y;
	odom_trans.transform.translation.z = 0.0;
	odom_trans.transform.rotation      = Model_pose.orientation;

	odom_broadcaster_.sendTransform(odom_trans);

	// 发布里程计消息(Pose + Twist)
	nav_msgs::Odometry msgl;
	msgl.header.stamp = current_time_;
	msgl.header.frame_id = "odom";

	msgl.pose.pose.position = Model_pose.position;
	msgl.pose.pose.orientation = Model_pose.orientation;
	//msgl.pose.covariance = odom_pose_covariance;

	msgl.child_frame_id = "base_footprint";
	msgl.twist.twist.linear = Model_twist.linear;
	msgl.twist.twist.angular= Model_twist.angular;
	//msgl.twist.covariance = odom_twist_covariance;
	
	pub_odom.publish(msgl);
	return true;
	
 }
