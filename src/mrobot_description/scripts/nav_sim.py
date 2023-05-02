#!/usr/bin/env python
import rospy
import std_msgs.msg
from ackermann_msgs.msg import AckermannDriveStamped
from geometry_msgs.msg import Twist

import time 
import threading
pub = rospy.Publisher("/ackermann_cmd_mux/output", AckermannDriveStamped,queue_size=1)

#次文件将ackermann_msgs/AckermannDriveStamped消息类型
#转换为geometry_msgs.msg/Twist

def thread_job():
    rospy.spin()

def callback(data):
    speed = data.linear.x 
    turn = data.angular.z

    msg = AckermannDriveStamped();
    msg.header.stamp = rospy.Time.now();
    msg.header.frame_id = "base_link";

    msg.drive.speed = speed;
    msg.drive.acceleration = 1;
    msg.drive.jerk = 1;
    msg.drive.steering_angle = turn
    msg.drive.steering_angle_velocity = 1

    pub.publish(msg)

def SubscribeAndPublish():
    rospy.init_node('nav_sim', anonymous=True)
    rospy.Subscriber('cmd_vel', Twist, callback,queue_size=1,buff_size=52428800) 
    #rospy.Subscriber('cmd_vel', Twist, callback,queue_size=1,buff_size=52428800)

    #注意，cmd_vel是由move_base所发出转递的是线速度和角速度，而我们需要变换成四个轮子的线速度和前轮的角度，
    # 注意，变换之后是角度而非角速度。直接通过三角函数变换即可，不过也可以通过修改参数实现：
    rospy.spin()


if __name__ == '__main__':
    try:
        SubscribeAndPublish()
    except rospy.ROSInterruptException:
        pass


########################
