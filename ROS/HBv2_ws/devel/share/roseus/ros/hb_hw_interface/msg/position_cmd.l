;; Auto-generated. Do not edit!


(when (boundp 'hb_hw_interface::position_cmd)
  (if (not (find-package "HB_HW_INTERFACE"))
    (make-package "HB_HW_INTERFACE"))
  (shadow 'position_cmd (find-package "HB_HW_INTERFACE")))
(unless (find-package "HB_HW_INTERFACE::POSITION_CMD")
  (make-package "HB_HW_INTERFACE::POSITION_CMD"))

(in-package "ROS")
;;//! \htmlinclude position_cmd.msg.html


(defclass hb_hw_interface::position_cmd
  :super ros::object
  :slots (_angle_cmd _velocity_cmd ))

(defmethod hb_hw_interface::position_cmd
  (:init
   (&key
    ((:angle_cmd __angle_cmd) (make-array 11 :initial-element 0.0 :element-type :float))
    ((:velocity_cmd __velocity_cmd) (make-array 11 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _angle_cmd __angle_cmd)
   (setq _velocity_cmd __velocity_cmd)
   self)
  (:angle_cmd
   (&optional __angle_cmd)
   (if __angle_cmd (setq _angle_cmd __angle_cmd)) _angle_cmd)
  (:velocity_cmd
   (&optional __velocity_cmd)
   (if __velocity_cmd (setq _velocity_cmd __velocity_cmd)) _velocity_cmd)
  (:serialization-length
   ()
   (+
    ;; float32[11] _angle_cmd
    (* 4    11)
    ;; float32[11] _velocity_cmd
    (* 4    11)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[11] _angle_cmd
     (dotimes (i 11)
       (sys::poke (elt _angle_cmd i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[11] _velocity_cmd
     (dotimes (i 11)
       (sys::poke (elt _velocity_cmd i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[11] _angle_cmd
   (dotimes (i (length _angle_cmd))
     (setf (elt _angle_cmd i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[11] _velocity_cmd
   (dotimes (i (length _velocity_cmd))
     (setf (elt _velocity_cmd i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get hb_hw_interface::position_cmd :md5sum-) "3c27cff7b342ce46d7f949fb78b6703f")
(setf (get hb_hw_interface::position_cmd :datatype-) "hb_hw_interface/position_cmd")
(setf (get hb_hw_interface::position_cmd :definition-)
      "float32[11] angle_cmd #cmd to arduino functions that move the arm.
float32[11] velocity_cmd ##cmd to arduino functions that move wheels.
")



(provide :hb_hw_interface/position_cmd "3c27cff7b342ce46d7f949fb78b6703f")


