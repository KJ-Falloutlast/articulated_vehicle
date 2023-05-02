
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TwistStamped.h"
#include "sensor_msgs/JointState.h"
#include "pid/wheel_vel.h"
#include <iostream>
using namespace std;
namespace sp
{
  // 创建一个消息类型 setpoint
  std_msgs::Float64 left_wheel_v;
  std_msgs::Float64 left_wheel_v_behind;
  std_msgs::Float64 right_wheel_v;
  std_msgs::Float64 right_wheel_v_behind;
  std_msgs::Float64 articulate_v;
  pid::wheel_vel wheel_v;
  //设置铰接车长度宽度 
  const double WHEEL_RADIUS = 0.75; //常量要大写,车轮半径
  const double VEHICLE_WIDTH = 1.5; //车宽
  const double lf = 1.500; //前车长
  const double lr = 1.467; //后车长

  double articulate_angle = 0;
  double d_articulate_angle = 0;
  double RobotV  = 0; //v
  double YawRate = 0; //wr
  double setpoint_left = 0;
  double setpoint_right = 0;
  double setpoint_left_behind = 0;
  double setpoint_right_behind = 0;
}

using namespace sp;


void getArticulateAngleCB(const sensor_msgs::JointState::ConstPtr &msg)
{
   int modelConst = msg->name.size();
   for(int i =0; i<modelConst; ++i)
   {
	  if(msg->name[i]=="behindbase_to_frontbase") //取得behindbase_to_frontbase的关节的位置和速度，
	  {
		 articulate_angle = msg->position[i]; //第i个的关节2个link的夹角
		 d_articulate_angle = msg->velocity[i];//第i个关节的角速度，关节求导
		 break;
	  }
   }
}

//这里得到的RobotV和YawRate是基于behind_baselink来计算的，但是要注意转弯的角速度和获取的twist.angular是相反的，因为车按j车左拐，link绕z轴逆时针转
void getCarControlCB(const geometry_msgs::TwistStamped vel_msg) //利用twistStamped来接收
{
    RobotV  = vel_msg.twist.linear.x;     //前进速度
    YawRate = vel_msg.twist.angular.z;   //转向的角速度dot{gama}
}

/**
 * @brief 
 * 1.计算左右轮期望速度, rear, front, left, right,先左右后，
 * 2.lf, lr, lLf, lRf, lLr, lRr; 
 * 3.wLf, wRf, wLr, wRr;  
 * 4.vLf, vRf, vLr, vRr; 
 * 5.WHEEL_RADIUS = 0.75; //常量要大写
     VEHICLE_WIDTH = 1.5;
    lf = 1.500;
    lr = 1.467;
 */
void pubVelocity()
{
   if(abs(articulate_angle)>0.1)//若articulate_angle>0.1rad
   {
		double LRr =0;
		double LRl =0;
		//前车的转弯半径
		double Rf = (lf*cos(articulate_angle)+lr)/sin(articulate_angle);//后车中心转弯半径
		LRr = Rf - VEHICLE_WIDTH/2; //右前轮的转弯半径
		LRl = Rf + VEHICLE_WIDTH/2; //左前轮的转弯半径
		setpoint_right = RobotV*(LRr/Rf); // v * lRr/Rf = vRf
		setpoint_left = RobotV*(LRl/Rf); // v * lRl/Rf = vLf
		//setpoint_left_behind =  setpoint_left ;
		//setpoint_right_behind = setpoint_right;

		//后车的转弯半径,LRr:右后轮的转弯半径，LRl：左后轮的转弯半径
		double Rr = (lr*cos(articulate_angle)+lf)/sin(articulate_angle); //前车中心的转弯半径     
		LRr = Rr - VEHICLE_WIDTH/2; //右后轮的转弯半径 = rRr
		LRl = Rr + VEHICLE_WIDTH/2; //左后轮的转弯半径 = rLr
		setpoint_right_behind = RobotV*(LRr/Rr);// v * LRl/Rr = vRr
		setpoint_left_behind = RobotV*(LRl/Rr); // v * LRl/Rr = vLr
		//setpoint left:左设定点
   }
   else 
   {
	//若铰接角度大于<= 0.1，则4个轮子的速度 = v
		setpoint_left = RobotV; 
		setpoint_right = RobotV;
		setpoint_left_behind =  setpoint_left ;
		setpoint_right_behind = setpoint_right;
   }

	//4个车轮的角速度
	left_wheel_v.data         = setpoint_left/WHEEL_RADIUS; // wLr = vLr / R 
	left_wheel_v_behind.data  = setpoint_left_behind/WHEEL_RADIUS;//wLr
	right_wheel_v.data        = setpoint_right/WHEEL_RADIUS;//wRf
	right_wheel_v_behind.data = setpoint_right_behind/WHEEL_RADIUS;//wRr
	articulate_v.data         = - YawRate;//转弯的角速度 = -YawRate(Twist), 左转按j，车子顺时针方向，

	// ? wheel_v是包含了左右前轮角速度的数据结构，但它并没有rqt_graph显示
	wheel_v.left_vel.data  = left_wheel_v.data;
	wheel_v.right_vel.data = right_wheel_v.data;


}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "transform_output");
	ROS_INFO("Starting setpoint publisher");
	ros::NodeHandle n;

	while (ros::ok() && ros::Time(0) == ros::Time::now())
	{
		ROS_INFO("Setpoint_node spinning, waiting for time to become non-zero");
		sleep(1);
	}


	//订阅键盘控制话题和关节话题，实际上我们需要订阅的是键盘控制节点的话题，然后读传入getcarcontrolCB
	ros::Subscriber subcar = n.subscribe("/xbot/cmd_mux/output", 1000, getCarControlCB);
	ros::Subscriber subangle = n.subscribe("/xbot/joint_states",1000, getArticulateAngleCB);
	//创建一个话题发布
	ros::Publisher setpoint_pub_l   = n.advertise<std_msgs::Float64>("/xbot/left_wheel_velocity_controller/command", 1000);//左前轮的角速度publisher
	ros::Publisher setpoint_pub_lb   = n.advertise<std_msgs::Float64>("/xbot/left_behind_wheel_velocity_controller/command", 1000);//左后轮的角速度publisher
	ros::Publisher setpoint_pub_r   = n.advertise<std_msgs::Float64>("/xbot/right_wheel_velocity_controller/command", 1000);//右后轮的角速度publisher
	ros::Publisher setpoint_pub_rb   = n.advertise<std_msgs::Float64>("/xbot/right_behind_wheel_velocity_controller/command", 1000);//左后轮的角速度publisher
	ros::Publisher articulate_pub_v = n.advertise<std_msgs::Float64>("/xbot/articulate_controller/command", 1000); //转弯角速度
	ros::Publisher setpoint_pub     = n.advertise<pid::wheel_vel>("/xbot/wheel_v/command", 1000); //左右轮速度

	//l是左前车轮， r是右前车轮, b = behind
	ros::Rate loop_rate(20);  
	while (ros::ok())
	{
		ros::spinOnce();
		pubVelocity();//发布速度
		setpoint_pub_l.publish(left_wheel_v);  
		setpoint_pub_lb.publish(left_wheel_v_behind);  
		setpoint_pub_r.publish(right_wheel_v);
		setpoint_pub_rb.publish(right_wheel_v_behind);
		articulate_pub_v.publish(articulate_v);
		setpoint_pub.publish(wheel_v);
		loop_rate.sleep();
	}
	return 0;
}
