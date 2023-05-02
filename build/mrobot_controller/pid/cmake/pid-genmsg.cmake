# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "pid: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ipid:/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(pid_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_custom_target(_pid_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pid" "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" "std_msgs/Float64"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(pid
  "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Float64.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pid
)

### Generating Services

### Generating Module File
_generate_module_cpp(pid
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pid
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(pid_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(pid_generate_messages pid_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_dependencies(pid_generate_messages_cpp _pid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pid_gencpp)
add_dependencies(pid_gencpp pid_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pid_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(pid
  "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Float64.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pid
)

### Generating Services

### Generating Module File
_generate_module_eus(pid
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pid
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(pid_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(pid_generate_messages pid_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_dependencies(pid_generate_messages_eus _pid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pid_geneus)
add_dependencies(pid_geneus pid_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pid_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(pid
  "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Float64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pid
)

### Generating Services

### Generating Module File
_generate_module_lisp(pid
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pid
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(pid_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(pid_generate_messages pid_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_dependencies(pid_generate_messages_lisp _pid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pid_genlisp)
add_dependencies(pid_genlisp pid_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pid_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(pid
  "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Float64.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pid
)

### Generating Services

### Generating Module File
_generate_module_nodejs(pid
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pid
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(pid_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(pid_generate_messages pid_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_dependencies(pid_generate_messages_nodejs _pid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pid_gennodejs)
add_dependencies(pid_gennodejs pid_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pid_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(pid
  "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Float64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pid
)

### Generating Services

### Generating Module File
_generate_module_py(pid
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pid
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(pid_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(pid_generate_messages pid_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kim-james/Tractor_ws/Run/articulated_vehicle_new_ws/src/mrobot_controller/pid/msg/wheel_vel.msg" NAME_WE)
add_dependencies(pid_generate_messages_py _pid_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pid_genpy)
add_dependencies(pid_genpy pid_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pid_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pid
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(pid_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/pid
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(pid_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pid
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(pid_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pid)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/pid
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(pid_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pid)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pid\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pid
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(pid_generate_messages_py std_msgs_generate_messages_py)
endif()
