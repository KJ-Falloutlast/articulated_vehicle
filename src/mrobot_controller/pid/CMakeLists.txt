cmake_minimum_required(VERSION 2.8.3)
project(pid)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  dynamic_reconfigure
  message_generation
  std_msgs
  tf
)

generate_dynamic_reconfigure_options(
    cfg/Pid.cfg
)

add_message_files(
    FILES
    wheel_vel.msg
)
generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
  INCLUDE_DIRS include
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime dynamic_reconfigure
)




include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake
)

#生成可执行文件
add_executable(controller src/controller.cpp src/pid.cpp) #controller
add_executable(plant_sim src/something_others/plant_sim.cpp) #plant_sim
add_executable(setpoint_node src/something_others/setpoint_node.cpp) #setpoint_node
add_executable(sim_time src/something_others/sim_time.cpp) #sim_time
add_executable(autotune src/something_others/autotune.cpp) #autotune(自动调节)
add_executable(servo_commands src/servo_commands.cpp) #servo_commands
add_executable(odom_pub src/odom_pub/odom_pub.cpp src/odom_pub/odom_cul.cpp) #odom_pub + odom_cul
add_executable(showpath src/show_path/showpath.cpp) #showpath
add_executable(Manual_control src/Manual_control.cpp) #Manual_control
add_executable(nav_sim src/nav_sim.cpp) #Manual_control


#指定依赖
add_dependencies(${PROJECT_NAME}_generate_messages_cpp ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(plant_sim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(setpoint_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(sim_time ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(autotune ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(servo_commands ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(odom_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(showpath ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(Manual_control ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


#这个函数为可执行文件或库添加链接库。
target_link_libraries(controller ${catkin_LIBRARIES}) #指定controller的链接库
target_link_libraries(plant_sim ${catkin_LIBRARIES})
target_link_libraries(setpoint_node ${catkin_LIBRARIES})
target_link_libraries(sim_time ${catkin_LIBRARIES})
target_link_libraries(autotune ${catkin_LIBRARIES})
target_link_libraries(servo_commands ${catkin_LIBRARIES})
target_link_libraries(odom_pub ${catkin_LIBRARIES})
target_link_libraries(showpath ${catkin_LIBRARIES})
target_link_libraries(Manual_control ${catkin_LIBRARIES})
target_link_libraries(nav_sim ${catkin_LIBRARIES})

install(TARGETS controller plant_sim setpoint_node sim_time autotune
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)
