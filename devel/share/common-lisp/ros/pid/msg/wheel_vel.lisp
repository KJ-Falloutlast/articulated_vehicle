; Auto-generated. Do not edit!


(cl:in-package pid-msg)


;//! \htmlinclude wheel_vel.msg.html

(cl:defclass <wheel_vel> (roslisp-msg-protocol:ros-message)
  ((left_vel
    :reader left_vel
    :initarg :left_vel
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (right_vel
    :reader right_vel
    :initarg :right_vel
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64)))
)

(cl:defclass wheel_vel (<wheel_vel>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <wheel_vel>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'wheel_vel)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pid-msg:<wheel_vel> is deprecated: use pid-msg:wheel_vel instead.")))

(cl:ensure-generic-function 'left_vel-val :lambda-list '(m))
(cl:defmethod left_vel-val ((m <wheel_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pid-msg:left_vel-val is deprecated.  Use pid-msg:left_vel instead.")
  (left_vel m))

(cl:ensure-generic-function 'right_vel-val :lambda-list '(m))
(cl:defmethod right_vel-val ((m <wheel_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pid-msg:right_vel-val is deprecated.  Use pid-msg:right_vel instead.")
  (right_vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <wheel_vel>) ostream)
  "Serializes a message object of type '<wheel_vel>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'left_vel) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'right_vel) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <wheel_vel>) istream)
  "Deserializes a message object of type '<wheel_vel>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'left_vel) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'right_vel) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<wheel_vel>)))
  "Returns string type for a message object of type '<wheel_vel>"
  "pid/wheel_vel")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'wheel_vel)))
  "Returns string type for a message object of type 'wheel_vel"
  "pid/wheel_vel")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<wheel_vel>)))
  "Returns md5sum for a message object of type '<wheel_vel>"
  "3893aed4c3e7acb03e6a5f6c31725f32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'wheel_vel)))
  "Returns md5sum for a message object of type 'wheel_vel"
  "3893aed4c3e7acb03e6a5f6c31725f32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<wheel_vel>)))
  "Returns full string definition for message of type '<wheel_vel>"
  (cl:format cl:nil "std_msgs/Float64 left_vel~%std_msgs/Float64 right_vel~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'wheel_vel)))
  "Returns full string definition for message of type 'wheel_vel"
  (cl:format cl:nil "std_msgs/Float64 left_vel~%std_msgs/Float64 right_vel~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <wheel_vel>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'left_vel))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'right_vel))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <wheel_vel>))
  "Converts a ROS message object to a list"
  (cl:list 'wheel_vel
    (cl:cons ':left_vel (left_vel msg))
    (cl:cons ':right_vel (right_vel msg))
))
