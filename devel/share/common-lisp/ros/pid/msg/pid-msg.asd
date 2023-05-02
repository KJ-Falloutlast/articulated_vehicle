
(cl:in-package :asdf)

(defsystem "pid-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "wheel_vel" :depends-on ("_package_wheel_vel"))
    (:file "_package_wheel_vel" :depends-on ("_package"))
  ))