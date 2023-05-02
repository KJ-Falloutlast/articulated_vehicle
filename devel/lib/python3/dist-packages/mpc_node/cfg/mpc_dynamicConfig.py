## *********************************************************
##
## File autogenerated for the mpc_node package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'name': 'Default', 'type': '', 'state': True, 'cstate': 'true', 'id': 0, 'parent': 0, 'parameters': [{'name': 'max_speed', 'type': 'double', 'default': 1.5, 'level': 0, 'description': 'max_speed', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'path_length', 'type': 'double', 'default': 6.0, 'level': 0, 'description': 'path_length', 'min': 0.1, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'goal_radius', 'type': 'double', 'default': 0.2, 'level': 0, 'description': 'goal_radius', 'min': 0.0, 'max': 1.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'controller_freq', 'type': 'double', 'default': 10.0, 'level': 0, 'description': 'controller_freq', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_steps', 'type': 'double', 'default': 20.0, 'level': 0, 'description': 'mpc_steps', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_ref_cte', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'mpc_ref_cte', 'min': 0.0, 'max': 1.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_ref_epsi', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'mpc_ref_epsi', 'min': 0.0, 'max': 1.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_ref_vel', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'mpc_ref_vel', 'min': 0.0, 'max': 10.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_cte', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'mpc_w_cte', 'min': 0.0, 'max': 1000.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_epsi', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'mpc_w_epsi', 'min': 0.0, 'max': 1000.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_vel', 'type': 'double', 'default': 0.5, 'level': 0, 'description': 'mpc_w_vel', 'min': 0.0, 'max': 1000.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_delta', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'mpc_w_delta', 'min': 0.0, 'max': 1000.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_accel', 'type': 'double', 'default': 2.0, 'level': 0, 'description': 'mpc_w_accel', 'min': 0.0, 'max': 1000.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_delta_d', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'mpc_w_delta_d', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_w_accel_d', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'mpc_w_accel_d', 'min': 0.1, 'max': 100.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_max_steering', 'type': 'double', 'default': 0.436, 'level': 0, 'description': 'mpc_max_steering', 'min': 0.1, 'max': 10.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_max_throttle', 'type': 'double', 'default': 0.8, 'level': 0, 'description': 'mpc_max_throttle', 'min': 0.0, 'max': 10.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'mpc_max_gama', 'type': 'double', 'default': 0.7, 'level': 0, 'description': 'mpc_max_gama', 'min': 0.0, 'max': 10.0, 'srcline': 291, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}], 'groups': [], 'srcline': 246, 'srcfile': '/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT', 'parentclass': '', 'parentname': 'Default', 'field': 'default', 'upper': 'DEFAULT', 'lower': 'groups'}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

