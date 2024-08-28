# 铲运车在ROS下的运动学模型构建与运动导航控制系统

该项目旨在创建一辆铰接式铲运机模型，在gazebo中进行建模仿真，并设计相应的环境感知，路径规划，路径跟踪控制模块。

系统使用Ubuntu 20.04 ，ros框架采用ROS-noetic

------

## 1.下载和编译

1. `git clone https://github.com/KJ-Falloutlast/articulated_vehicle.git `  

    

2. 安装所需要的依赖

    ```
    sudo apt-get install ros-noetic-velocity-controllers 
    sudo apt-get install ros-noetic-position-controllers 
    ```

3. 进行编译

    ```
    catkin_make
    ```

## 2.启动方法

1. 启动底盘驱动:`roslaunch mrobot_description rosbot_spawn.launch`
2. 启动导航:`roslaunch mrobot_navigation amcl_nav.launch`




## 3.效果图                           
#### 3-0.demo_video  
* watching the video of our [articulated_vehicle](https://www.youtube.com/watch?v=HY1pLlN2mGI)!
![articulated_vehicle](https://github.com/user-attachments/assets/0f0f839d-19da-43ea-95dd-446bb5c377d8)


#### 3-1.rqt_graph    

![rosgraph_amcl](https://obsidians-pics.oss-cn-beijing.aliyuncs.com/rosgraph_amcl.png)

#### 3-2.铰接车的坐标图

![2023-02-15 00-51-50 的屏幕截图](https://obsidians-pics.oss-cn-beijing.aliyuncs.com/2023-02-15%2000-51-50%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 3-3.铰接车的tf_tree

![rqt_tree](https://obsidians-pics.oss-cn-beijing.aliyuncs.com/rqt_tree.png)
