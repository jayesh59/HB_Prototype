
#include <hw_control_interface_myversion/generic_hw_control_loop_myversion.h>
#include <hb_hw_interface/hw_interface_myversion.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "hw_interface_myversion");
  ros::NodeHandle nh; 

  // NOTE: We run the ROS loop in a separate thread as external calls such
  // as service callbacks to load controllers can block the (main) control loop
  ros::AsyncSpinner spinner(3);
  spinner.start();

  // Create the hardware interface specific to your robot
  std::shared_ptr<hw::HWInterface> hw_interface_myversion_instance 
   (new hw::HWInterface(nh));
  hw_interface_myversion_instance ->init(); // size and register required interfaces inside generic_hw_interface.cpp

  // Start the control loop
  generic::GenericHWControlLoop control_loop(nh, hw_interface_myversion_instance);
  control_loop.run(); // Blocks until shutdown signal recieved -> read -> update -> write -> repeat inside generic_hw_control_loop.cpp

  return 0;
}