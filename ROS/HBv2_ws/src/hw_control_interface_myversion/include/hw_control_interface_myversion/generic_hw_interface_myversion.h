#ifndef GENERIC_ROS_CONTROL_GENERIC_HW_INTERFACE_H
#define GENERIC_ROS_CONTROL_GENERIC_HW_INTERFACE_H

    // ROS
    #include <ros/ros.h>
    #include <urdf/model.h>

    // ROS Controls
    #include <hardware_interface/robot_hw.h>
    #include <hardware_interface/joint_state_interface.h>
    #include <hardware_interface/joint_command_interface.h>
    #include <controller_manager/controller_manager.h>
    #include <joint_limits_interface/joint_limits.h>
    #include <joint_limits_interface/joint_limits_interface.h>
    #include <joint_limits_interface/joint_limits_rosparam.h>
    #include <joint_limits_interface/joint_limits_urdf.h>

    namespace generic
    {
        class GenericHWInterface : public hardware_interface::RobotHW
        {
            public:
                GenericHWInterface(const ros::NodeHandle& nh, urdf::Model* urdf_model = NULL);

                virtual ~GenericHWInterface(){}

                virtual void init();

                virtual void read(ros::Duration& elapsed_time) = 0;
                virtual void read(const ros::Time& /*time*/, const ros::Duration& period) override
                {
                    ros::Duration elapsed_time = period;
                    read(elapsed_time);
                }

                virtual void write(ros::Duration& elapsed_time) = 0;
                virtual void write(const ros::Time& /*time*/, const ros::Duration& period) override
                {
                    ros::Duration elapsed_time = period;
                    write(elapsed_time);
                }

                virtual void reset();

                virtual bool canSwitch(const std::list<hardware_interface::ControllerInfo>& start_list,
                                        const std::list<hardware_interface::ControllerInfo>& stop_list) const
                {
                    return true;
                }

                virtual void doSwitch(const std::list<hardware_interface::ControllerInfo>& start_list,
                                        const std::list<hardware_interface::ControllerInfo>& stop_list)
                {
                }


                virtual void registerJointLimits(const hardware_interface::JointHandle& joint_handle_position,
                                                const hardware_interface::JointHandle& joint_handle_velocity,
                                                const hardware_interface::JointHandle& joint_handle_effort, std::size_t joint_id);

                /** Enforce limits for all values before writing */
                virtual void enforceLimits(ros::Duration& period) = 0;
                virtual void printState();
                std::string printStateHelper();
                std::string printCommandHelper();

            protected:
                virtual void loadURDF(const ros::NodeHandle& nh, std::string param_name);

                std::string name_;
                ros::NodeHandle nh_;

                // Hardware interfaces
                hardware_interface::JointStateInterface joint_state_interface_;
                hardware_interface::PositionJointInterface position_joint_interface_;
                hardware_interface::VelocityJointInterface velocity_joint_interface_;
                hardware_interface::EffortJointInterface effort_joint_interface_;

                // Joint limits interfaces - Saturation
                joint_limits_interface::PositionJointSaturationInterface pos_jnt_sat_interface_;
                joint_limits_interface::VelocityJointSaturationInterface vel_jnt_sat_interface_;
                joint_limits_interface::EffortJointSaturationInterface eff_jnt_sat_interface_;

                // Joint limits interfaces - Soft limits
                joint_limits_interface::PositionJointSoftLimitsInterface pos_jnt_soft_limits_;
                joint_limits_interface::VelocityJointSoftLimitsInterface vel_jnt_soft_limits_;
                joint_limits_interface::EffortJointSoftLimitsInterface eff_jnt_soft_limits_;

                // Configuration
                std::vector<std::string> joint_names_;
                std::size_t num_joints_;
                urdf::Model* urdf_model_;

                // Modes
                bool use_rosparam_joint_limits_;
                bool use_soft_limits_if_available_;

                // States
                std::vector<double> joint_position_;
                std::vector<double> joint_velocity_;
                std::vector<double> joint_effort_;

                // Commands
                std::vector<double> joint_position_command_;
                std::vector<double> joint_velocity_command_;
                std::vector<double> joint_effort_command_;

                // Copy of limits, in case we need them later in our control stack
                std::vector<double> joint_position_lower_limits_;
                std::vector<double> joint_position_upper_limits_;
                std::vector<double> joint_velocity_limits_;
                std::vector<double> joint_effort_limits_;

        }; 

    }

#endif  