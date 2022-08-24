; Auto-generated. Do not edit!


(cl:in-package hb_hw_interface-msg)


;//! \htmlinclude position_cmd.msg.html

(cl:defclass <position_cmd> (roslisp-msg-protocol:ros-message)
  ((angle_cmd
    :reader angle_cmd
    :initarg :angle_cmd
    :type (cl:vector cl:float)
   :initform (cl:make-array 11 :element-type 'cl:float :initial-element 0.0))
   (velocity_cmd
    :reader velocity_cmd
    :initarg :velocity_cmd
    :type (cl:vector cl:float)
   :initform (cl:make-array 11 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass position_cmd (<position_cmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <position_cmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'position_cmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hb_hw_interface-msg:<position_cmd> is deprecated: use hb_hw_interface-msg:position_cmd instead.")))

(cl:ensure-generic-function 'angle_cmd-val :lambda-list '(m))
(cl:defmethod angle_cmd-val ((m <position_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hb_hw_interface-msg:angle_cmd-val is deprecated.  Use hb_hw_interface-msg:angle_cmd instead.")
  (angle_cmd m))

(cl:ensure-generic-function 'velocity_cmd-val :lambda-list '(m))
(cl:defmethod velocity_cmd-val ((m <position_cmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hb_hw_interface-msg:velocity_cmd-val is deprecated.  Use hb_hw_interface-msg:velocity_cmd instead.")
  (velocity_cmd m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <position_cmd>) ostream)
  "Serializes a message object of type '<position_cmd>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'angle_cmd))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'velocity_cmd))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <position_cmd>) istream)
  "Deserializes a message object of type '<position_cmd>"
  (cl:setf (cl:slot-value msg 'angle_cmd) (cl:make-array 11))
  (cl:let ((vals (cl:slot-value msg 'angle_cmd)))
    (cl:dotimes (i 11)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'velocity_cmd) (cl:make-array 11))
  (cl:let ((vals (cl:slot-value msg 'velocity_cmd)))
    (cl:dotimes (i 11)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<position_cmd>)))
  "Returns string type for a message object of type '<position_cmd>"
  "hb_hw_interface/position_cmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position_cmd)))
  "Returns string type for a message object of type 'position_cmd"
  "hb_hw_interface/position_cmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<position_cmd>)))
  "Returns md5sum for a message object of type '<position_cmd>"
  "3c27cff7b342ce46d7f949fb78b6703f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'position_cmd)))
  "Returns md5sum for a message object of type 'position_cmd"
  "3c27cff7b342ce46d7f949fb78b6703f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<position_cmd>)))
  "Returns full string definition for message of type '<position_cmd>"
  (cl:format cl:nil "float32[11] angle_cmd #cmd to arduino functions that move the arm.~%float32[11] velocity_cmd ##cmd to arduino functions that move wheels.~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'position_cmd)))
  "Returns full string definition for message of type 'position_cmd"
  (cl:format cl:nil "float32[11] angle_cmd #cmd to arduino functions that move the arm.~%float32[11] velocity_cmd ##cmd to arduino functions that move wheels.~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <position_cmd>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'angle_cmd) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'velocity_cmd) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <position_cmd>))
  "Converts a ROS message object to a list"
  (cl:list 'position_cmd
    (cl:cons ':angle_cmd (angle_cmd msg))
    (cl:cons ':velocity_cmd (velocity_cmd msg))
))
