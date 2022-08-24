#include <Arduino.h>
#include <Actuator.h>
#include <ctype.h>
#include <Wire.h>
#include <ros.h>
#include <Test_Package/position_cmd.h>
#include <Test_Package/state_update.h>

/*
    array for analog pins
    array for pwm pins
    array for gear ratios
    array for ang_min_hall values
    array for ang_max_hall values
    array for zero_point angles
*/
int analogPins[16] = {54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69};
int pwmPins[13] = {2,3,5,6,7,8,9,10,11,12,44,45,46};
float Wheel_R=0, Wheel_L=0, Servo = 0;
byte data[3] = {0,0,0};


//gear ratios = {wrist, elbow, shoulder};
float gearRatios[3] = {53.393,238.235,424.827};

//array[6] = {wrist.theta.value, elbow.theta.value, shoulder.theta.value, wrist.fi.value, elbow.fi.value, shoulder.fi.value};
int minHallValues[6] = {0,0,0,0,0,0}; 
int maxHallValues[6] = {1023,1023,1023,1023,1023,1023};

joint wrist(pwmPins[0],pwmPins[1],analogPins[0],pwmPins[2],pwmPins[3],analogPins[2]); 
joint elbow(pwmPins[4],pwmPins[5],analogPins[4],pwmPins[6],pwmPins[7],analogPins[6]); 
joint shoulder(pwmPins[8],pwmPins[9],analogPins[8],pwmPins[10],pwmPins[11],analogPins[10]);

joint joints[3] = {wrist, elbow, shoulder};
//ros node setup
ros::NodeHandle nh;
int flag_for_publish = 0;

//subscriber
void arm_pose_change(const Test_Package::position_cmd &msg)
{
  float fi;
  float theta;
  int Wheel_L_norm, Wheel_R_norm, Servo_int;
  int max_vel = 1, min_vel = 0;

  for(int i=0; i<5; i+=2)
  {
    fi = msg.angle_cmd[0+i];
    theta = msg.angle_cmd[1+i];

    joints[i/2].input(fi, theta);
  }
  Servo = msg.angle_cmd[6];
  Servo_int = Servo;
  Wheel_L = msg.velocity_cmd[7];
  Wheel_R = msg.velocity_cmd[9];

  Wheel_L_norm = 255*(Wheel_L-min_vel)/(max_vel-min_vel);
  Wheel_R_norm = 255*(Wheel_R-min_vel)/(max_vel-min_vel);

  data[3] = {Wheel_R_norm, Wheel_L_norm, Servo_int};
  Wire.beginTransmission(1);
  Wire.write(data, 3);
  Wire.endTransmission();


  flag_for_publish = 1;
}

ros::Subscriber<Test_Package::position_cmd> sub("/ros2arduino", &arm_pose_change);        

//publisher
Test_Package::state_update state;
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
    for(int i=0; i<3; i++)
    {
        joints[i].initiate_pins();
        
        joints[i].theta.gear_ratio = gearRatios[i];
        joints[i].fi.gear_ratio = gearRatios[i];
        joints[i].theta.min_hall = minHallValues[0+i];
        joints[i].theta.max_hall = maxHallValues[0+i];
        joints[i].fi.min_hall = minHallValues[3+i];
        joints[i].fi.max_hall = maxHallValues[3+i];
    }

    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub);
    Wire.begin();

}

void loop() 
{
  nh.spinOnce();

  if(flag_for_publish==1)
  {
    for(int i=0; i<5; i+=2)
    {
      state.c_angles[0+i] = joints[i/2].c_fi;
      state.c_angles[1+i] = joints[i/2].c_theta;
    }
    state.c_angles[6] = Servo;
    state.c_velocities[7] = Wheel_L;
    state.c_velocities[8] = Wheel_L;
    state.c_velocities[9] = Wheel_R;
    state.c_velocities[10] = Wheel_R;

    pub.publish(&state);
    flag_for_publish = 0; 
  }
  
}
