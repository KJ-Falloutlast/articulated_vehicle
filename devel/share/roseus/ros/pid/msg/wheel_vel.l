;; Auto-generated. Do not edit!


(when (boundp 'pid::wheel_vel)
  (if (not (find-package "PID"))
    (make-package "PID"))
  (shadow 'wheel_vel (find-package "PID")))
(unless (find-package "PID::WHEEL_VEL")
  (make-package "PID::WHEEL_VEL"))

(in-package "ROS")
;;//! \htmlinclude wheel_vel.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass pid::wheel_vel
  :super ros::object
  :slots (_left_vel _right_vel ))

(defmethod pid::wheel_vel
  (:init
   (&key
    ((:left_vel __left_vel) (instance std_msgs::Float64 :init))
    ((:right_vel __right_vel) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _left_vel __left_vel)
   (setq _right_vel __right_vel)
   self)
  (:left_vel
   (&rest __left_vel)
   (if (keywordp (car __left_vel))
       (send* _left_vel __left_vel)
     (progn
       (if __left_vel (setq _left_vel (car __left_vel)))
       _left_vel)))
  (:right_vel
   (&rest __right_vel)
   (if (keywordp (car __right_vel))
       (send* _right_vel __right_vel)
     (progn
       (if __right_vel (setq _right_vel (car __right_vel)))
       _right_vel)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Float64 _left_vel
    (send _left_vel :serialization-length)
    ;; std_msgs/Float64 _right_vel
    (send _right_vel :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Float64 _left_vel
       (send _left_vel :serialize s)
     ;; std_msgs/Float64 _right_vel
       (send _right_vel :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Float64 _left_vel
     (send _left_vel :deserialize buf ptr-) (incf ptr- (send _left_vel :serialization-length))
   ;; std_msgs/Float64 _right_vel
     (send _right_vel :deserialize buf ptr-) (incf ptr- (send _right_vel :serialization-length))
   ;;
   self)
  )

(setf (get pid::wheel_vel :md5sum-) "3893aed4c3e7acb03e6a5f6c31725f32")
(setf (get pid::wheel_vel :datatype-) "pid/wheel_vel")
(setf (get pid::wheel_vel :definition-)
      "std_msgs/Float64 left_vel
std_msgs/Float64 right_vel

================================================================================
MSG: std_msgs/Float64
float64 data
")



(provide :pid/wheel_vel "3893aed4c3e7acb03e6a5f6c31725f32")


