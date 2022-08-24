#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>

ros::NodeHandle nh; //node handle

std_msgs::String str_msg; // making a variable for the message type. for custom purposes the message type and library will be different.
ros::Publisher chatter("chatter", &str_msg); //making the publisher object like generally done in normall c++ node.

char hello[13] = "hello world!"; //test message data to publish.

void setup()
{
  nh.initNode(); //initialize node in the void setup
  nh.advertise(chatter);
}   

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}