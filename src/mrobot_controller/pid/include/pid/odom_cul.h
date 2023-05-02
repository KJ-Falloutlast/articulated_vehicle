#ifndef PID_H
#define PID_H

#include <vector>
#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <boost/asio.hpp>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <gazebo_msgs/ModelStates.h>
#include "pid/wheel_vel.h"

#include <dynamic_reconfigure/server.h>
#include <pid/PidConfig.h>
//实际上是把4轮小车的速度转换为2轮的差速模型来发布里程计信息
using namespace std;
     class Odomcul{
	public:
	    Odomcul(ros::NodeHandle _n);
	    bool encodercul();
	    bool imucul();
	    bool publishOdom();

	    void velCallback(const pid::wheel_vel::ConstPtr &msg); //轮速的回调函数
	    void cmdCallback(const gazebo_msgs::ModelStates::ConstPtr &msg);
	    void reconfigureCallback(pid::PidConfig& config, uint32_t lever);
	    
	    bool issimulate = true;
	private:
	    ros::Time current_time_, last_time_;

	   double x_   = 0; 
	   double y_   = 0;
	   double th_  = 0; //位移和转角
	
	   double vx_  = 0; //x速度
	   double vy_  = 0; //y方向速度
	   double vth_ = 0; //角速度
	   double vel_left = 0 ; //左轮的速度
	   double vel_right = 0; //右轮的速度
	   double slip_n = 0;

	    geometry_msgs::Quaternion odom_quat;
	    geometry_msgs::Pose Model_pose; //里程计消息既有pose又有twist
	    geometry_msgs::Twist Model_twist; //
            ros::NodeHandle _nh;
            ros::Publisher pub_odom;

	    tf::TransformBroadcaster odom_broadcaster_;

    };
#endif
