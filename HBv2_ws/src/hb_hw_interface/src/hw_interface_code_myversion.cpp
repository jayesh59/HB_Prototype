#include <hb_hw_interface/hw_interface_myversion.h>

namespace hw
{

    HWInterface::HWInterface(ros::NodeHandle &nh, urdf::Model *urdf_model) 
    : generic::GenericHWInterface(nh, urdf_model)
    {
        states_sub = nh.subscribe("/mega/arduino2ros", 1, &HWInterface::state_sub_callback, this);
        cmd_pub = nh.advertise<hb_hw_interface::position_cmd>("/mega/ros2arduino",1);

        ROS_INFO("HWInterface declared.");
    }

    void HWInterface::state_sub_callback(const hb_hw_interface::state_update::ConstPtr &msg)
    {
        //std::vector<double> joint_position_;
        for(int i=0; i<num_joints_; i++)
        {
            joint_position_[i] = msg->c_angles[i]*DEG_TO_RAD;
            joint_velocity_[i] = msg->c_velocities[i];
        }
    }

    void HWInterface::init()
    {
        // Call parent class version of this function
        /*
        this looks at controller yaml "hardware" namespace to get "joints". from this list the number of joints is known so hardware interfaces are initialized.
        it starts a joint_state, position, velocity and effort iterface. joint limits are also grabbed from parameter server urdf if urdf=NULL.
        */
        generic::GenericHWInterface::init();

        ROS_INFO("HWInterface initiated.");
    }

    void HWInterface::read(ros::Duration &elapsed_time)
    {   
        ros::spinOnce();
    }

    void HWInterface::write(ros::Duration &elapsed_time)
    {
        //std::vector<double> joint_position_command_;

        static hb_hw_interface::position_cmd pos_cmd;

        for(int i=0; i<num_joints_; i++)
        {
            pos_cmd.angle_cmd[i] = joint_position_command_[i]*RAD_TO_DEG;
            pos_cmd.velocity_cmd[i] = joint_velocity_command_[i];
        }

        cmd_pub.publish(pos_cmd);
    } 

    void HWInterface::enforceLimits(ros::Duration &period)
    {
    }

}