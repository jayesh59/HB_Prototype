;; Auto-generated. Do not edit!


(when (boundp 'hb_hw_interface::state_update)
  (if (not (find-package "HB_HW_INTERFACE"))
    (make-package "HB_HW_INTERFACE"))
  (shadow 'state_update (find-package "HB_HW_INTERFACE")))
(unless (find-package "HB_HW_INTERFACE::STATE_UPDATE")
  (make-package "HB_HW_INTERFACE::STATE_UPDATE"))

(in-package "ROS")
;;//! \htmlinclude state_update.msg.html


(defclass hb_hw_interface::state_update
  :super ros::object
  :slots (_c_angles _c_velocities ))

(defmethod hb_hw_interface::state_update
  (:init
   (&key
    ((:c_angles __c_angles) (make-array 11 :initial-element 0.0 :element-type :float))
    ((:c_velocities __c_velocities) (make-array 11 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _c_angles __c_angles)
   (setq _c_velocities __c_velocities)
   self)
  (:c_angles
   (&optional __c_angles)
   (if __c_angles (setq _c_angles __c_angles)) _c_angles)
  (:c_velocities
   (&optional __c_velocities)
   (if __c_velocities (setq _c_velocities __c_velocities)) _c_velocities)
  (:serialization-length
   ()
   (+
    ;; float32[11] _c_angles
    (* 4    11)
    ;; float32[11] _c_velocities
    (* 4    11)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[11] _c_angles
     (dotimes (i 11)
       (sys::poke (elt _c_angles i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[11] _c_velocities
     (dotimes (i 11)
       (sys::poke (elt _c_velocities i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[11] _c_angles
   (dotimes (i (length _c_angles))
     (setf (elt _c_angles i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[11] _c_velocities
   (dotimes (i (length _c_velocities))
     (setf (elt _c_velocities i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get hb_hw_interface::state_update :md5sum-) "ef499ec12d5d495e7c8a49b8fded425f")
(setf (get hb_hw_interface::state_update :datatype-) "hb_hw_interface/state_update")
(setf (get hb_hw_interface::state_update :definition-)
      "float32[11] c_angles #current angle values as output as a result of change in posture due to cmd from ROS.
float32[11] c_velocities #current velocity values as output as a result of change in velocity of wheels due to cmd from ROS.
")



(provide :hb_hw_interface/state_update "ef499ec12d5d495e7c8a49b8fded425f")


