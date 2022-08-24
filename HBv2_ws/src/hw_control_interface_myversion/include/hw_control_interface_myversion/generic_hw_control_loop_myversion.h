#include <time.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/robot_hw.h>

namespace generic
{
    static const double BILLION = 1000000000.0;

    class GenericHWControlLoop
    {
        public:
            GenericHWControlLoop(ros::NodeHandle& nh, std::shared_ptr<hardware_interface::RobotHW> hardware_interface);
            void run();

        protected:
            void update();
            ros::NodeHandle nh_;
            std::string name_ = "generic_hw_control_loop";
            ros::Duration desired_update_period_;
            double cycle_time_error_threshold_;

            ros::Duration elapsed_time_;
            double loop_hz_;
            struct timespec last_time_;
            struct timespec current_time_;

            std::shared_ptr<controller_manager::ControllerManager> controller_manager_;
            std::shared_ptr<hardware_interface::RobotHW> hardware_interface_;

    };
} 
