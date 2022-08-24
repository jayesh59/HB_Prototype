; Auto-generated. Do not edit!


(cl:in-package hb_hw_interface-msg)


;//! \htmlinclude state_update.msg.html

(cl:defclass <state_update> (roslisp-msg-protocol:ros-message)
  ((c_angles
    :reader c_angles
    :initarg :c_angles
    :type (cl:vector cl:float)
   :initform (cl:make-array 11 :element-type 'cl:float :initial-element 0.0))
   (c_velocities
    :reader c_velocities
    :initarg :c_velocities
    :type (cl:vector cl:float)
   :initform (cl:make-array 11 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass state_update (<state_update>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <state_update>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'state_update)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hb_hw_interface-msg:<state_update> is deprecated: use hb_hw_interface-msg:state_update instead.")))

(cl:ensure-generic-function 'c_angles-val :lambda-list '(m))
(cl:defmethod c_angles-val ((m <state_update>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hb_hw_interface-msg:c_angles-val is deprecated.  Use hb_hw_interface-msg:c_angles instead.")
  (c_angles m))

(cl:ensure-generic-function 'c_velocities-val :lambda-list '(m))
(cl:defmethod c_velocities-val ((m <state_update>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hb_hw_interface-msg:c_velocities-val is deprecated.  Use hb_hw_interface-msg:c_velocities instead.")
  (c_velocities m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <state_update>) ostream)
  "Serializes a message object of type '<state_update>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'c_angles))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'c_velocities))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <state_update>) istream)
  "Deserializes a message object of type '<state_update>"
  (cl:setf (cl:slot-value msg 'c_angles) (cl:make-array 11))
  (cl:let ((vals (cl:slot-value msg 'c_angles)))
    (cl:dotimes (i 11)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'c_velocities) (cl:make-array 11))
  (cl:let ((vals (cl:slot-value msg 'c_velocities)))
    (cl:dotimes (i 11)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<state_update>)))
  "Returns string type for a message object of type '<state_update>"
  "hb_hw_interface/state_update")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'state_update)))
  "Returns string type for a message object of type 'state_update"
  "hb_hw_interface/state_update")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<state_update>)))
  "Returns md5sum for a message object of type '<state_update>"
  "ef499ec12d5d495e7c8a49b8fded425f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'state_update)))
  "Returns md5sum for a message object of type 'state_update"
  "ef499ec12d5d495e7c8a49b8fded425f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<state_update>)))
  "Returns full string definition for message of type '<state_update>"
  (cl:format cl:nil "float32[11] c_angles #current angle values as output as a result of change in posture due to cmd from ROS.~%float32[11] c_velocities #current velocity values as output as a result of change in velocity of wheels due to cmd from ROS.~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'state_update)))
  "Returns full string definition for message of type 'state_update"
  (cl:format cl:nil "float32[11] c_angles #current angle values as output as a result of change in posture due to cmd from ROS.~%float32[11] c_velocities #current velocity values as output as a result of change in velocity of wheels due to cmd from ROS.~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <state_update>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'c_angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'c_velocities) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <state_update>))
  "Converts a ROS message object to a list"
  (cl:list 'state_update
    (cl:cons ':c_angles (c_angles msg))
    (cl:cons ':c_velocities (c_velocities msg))
))
