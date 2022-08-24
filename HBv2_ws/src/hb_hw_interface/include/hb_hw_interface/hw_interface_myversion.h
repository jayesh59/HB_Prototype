#ifndef HW_INTERFACE_MYVERSION_H
#define HW_INTERFACE_MYVERSION_H
 
#include "hw_control_interface_myversion/generic_hw_interface_myversion.h"
#include <hb_hw_interface/position_cmd.h>
#include <hb_hw_interface/state_update.h>

#define DEG_TO_RAD 0.01745329251
#define RAD_TO_DEG 57.2957795131

namespace hw
{
    class HWInterface : public generic::GenericHWInterface
    {

        public:
            HWInterface(ros::NodeHandle& nh, urdf::Model* urdf_model = NULL);

            virtual void init();
            virtual void read(ros::Duration &elapsed_time);
            virtual void write(ros::Duration &elapsed_time);
            virtual void enforceLimits(ros::Duration &period);

        protected:
            ros::Subscriber states_sub;
            ros::Publisher cmd_pub;
            
            void state_sub_callback(const hb_hw_interface::state_update::ConstPtr &msg);


    };  
} 
 
#endif