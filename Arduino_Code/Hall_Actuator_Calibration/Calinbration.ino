/*
actuator testing and calibration code
this file requires to accomplish the following tasks
    - get the hall encoder values to get the mean value for the actuator. 
      so that the acquired value can be used for binary classification of the poles of magnets. 

recieve the values from the hall sensors.
add the values in a loop till n no. of values recieved.
then divide the sum from the n and note that threshold value for the axis of the joint.
the gearbox will not be attached for the calibration stage as the limits are not attached.
*/

#include <ctype.h>
#include <Arduino.h>

char c = 0;
int a=0, count =0, flag = 1, thresh = 0, sum = 0, min = 255, max = 0;


void setup() 
{
  //pinMode(12,OUTPUT);
  //pinMode(13,OUTPUT);
  pinMode(A1, INPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  analogWrite(3, 250);
  analogWrite(9, 0);
  a = analogRead(A1);

  Serial.print(a);
  Serial.println(',');
}

