#include <ros/ros.h> //ros
#include <geometry_msgs/Twist.h> //Twist
#include <geometry_msgs/TwistStamped.h> //Twist
#include <iostream> //iostream
using namespace std;
//定义一个类
class NavSim
{
public:
    //相关消息类型
    geometry_msgs::TwistStamped cmd_vel;//发布的的cmd消息
    double v, w;//线速度和角速度
    ros::NodeHandle nh; //
    ros::Subscriber sub_cmd; //订阅cmd_vel消息
    ros::Publisher pub_twist;//发布twist消息
public:
    NavSim(ros::NodeHandle n);
    void twistCB(const geometry_msgs::Twist::ConstPtr& msg);
};

NavSim::NavSim(ros::NodeHandle n)
{
    nh = n;
    //接收来自movebase的消息
    sub_cmd = nh.subscribe<geometry_msgs::Twist>("cmd_vel", 100, boost::bind(&NavSim::twistCB, this, _1));//接受者有话题 + 队列长度 + 回调函数
    // ros::Subscriber 对象名2 = n.subscribe("话题名", 队列长度, 回调函数名);
    //@note 这里要注意，在类里面，需要加上boost::bind(&NavSim::twistCB, this, _1)作为整个回调函数, 发布twiststamped
    pub_twist = nh.advertise<geometry_msgs::TwistStamped>("/xbot/cmd_mux/output", 100);//以100的频率发布/xbot/cmd_mux/output
    // 接受者 = 话题名 + 队列长度
    // ros::Publisher 发布者 = n.advertise<消息类型>("话题名", 队列长度);
}

void NavSim::twistCB(const geometry_msgs::Twist::ConstPtr& msg)//必须加const才行
{
    cmd_vel.header.stamp = ros::Time::now();//时间戳
    cmd_vel.header.frame_id = "base_footprint";
    cmd_vel.twist.angular.x = 0;
    cmd_vel.twist.angular.y = 0;
    cmd_vel.twist.angular.z = msg->angular.z;

    cmd_vel.twist.linear.x = msg->linear.x; 
    cmd_vel.twist.linear.y = 0;
    cmd_vel.twist.linear.z = 0;
    //以base_footprint作为消息订阅
    //发布控制消息
    pub_twist.publish(cmd_vel);
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "nav_sim");//ros的常规初始化
    ros::NodeHandle n;
    NavSim Nav(n);
    ros::spin();
}