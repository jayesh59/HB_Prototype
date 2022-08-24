
(cl:in-package :asdf)

(defsystem "hb_hw_interface-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "position_cmd" :depends-on ("_package_position_cmd"))
    (:file "_package_position_cmd" :depends-on ("_package"))
    (:file "state_update" :depends-on ("_package_state_update"))
    (:file "_package_state_update" :depends-on ("_package"))
  ))