/*
    this file is to test the actuator control using ROS.
    this file need to accomplish the following requirements.
        - connect to the actuator's both axis for control.
        - read the angle values from the hall sensors and print on serial monitor.
        - communicate with ROS.
        - must add the homing function.
*/

#include <Actuator.h>
#include <ctype.h>
#include <ros.h>
#include <arm_launch/position_cmd.h>
#include <arm_launch/state_update.h>

/*
    array for analog pins
    array for pwm pins
    array for gear ratios
    array for ang_min_hall values
    array for ang_max_hall values
    array for zero_point angles
*/

int analogPins[4] = {14,15,16,17};
int pwmPins[4] = {3,9,10,11};

//gear ratios = {wrist, elbow, shoulder};
float gearRatios = ;

//array[6] = {wrist.theta.value, elbow.theta.value, shoulder.theta.value, wrist.fi.value, elbow.fi.value, shoulder.fi.value};
int minHallValues[2] = {}; 
int maxHallValues[2] = {};

joint act(pwmPins[0],pwmPins[1],analogPins[0],analogPins[1],pwmPins[2],pwmPins[3],analogPins[2],analogPins[3]); 

//ros node setup
ros::NodeHandle nh;
int flag_for_publish = 0;

//subscriber
void arm_pose_change(const arm_launch::position_cmd &msg)
{
  float fi;
  float theta;

  fi = msg.angle_cmd[0];
  theta = msg.angle_cmd[1];

  act.input(fi, theta);

  flag_for_publish = 1;
}

ros::Subscriber<arm_launch::position_cmd> sub("/ros2arduino", &arm_pose_change);        

//publisher
arm_launch::state_update state;
ros::Publisher pub("/arduino2ros", &state);

void setup() 
{
    /*
    joint.theta.gear_ratio = 75;
    joint.fi.gear_ratio = 75;
    joint.initiate_pins();
    joint.c_theta = joint.theta.home();
    joint.c_fi = joint.fi.home();
    Serial.begin(9600);
    joint.theta.min_hall = 894;
    joint.theta.max_hall = 1023;
    joint.fi.min_hall = 894;
    joint.fi.max_hall = 1023;
    */
    
    act.initiate_pins();    
    act.theta.gear_ratio = gearRatios;
    act.fi.gear_ratio = gearRatios;
    act.theta.min_hall = minHallValues[0];
    act.theta.max_hall = maxHallValues[0];
    act.fi.min_hall = minHallValues[1];
    act.fi.max_hall = maxHallValues[1];

    act.theta.home();
    act.fi.home();
    
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub);
}

void loop() 
{
  nh.spinOnce();

  if(flag_for_publish==1)
  {
    state.c_angles[0] = act.c_fi;
    state.c_angles[1] = act.c_theta;
    Serial.print(act.fi, act.theta);
    pub.publish(&state);
    flag_for_publish = 0; 
  }  
}