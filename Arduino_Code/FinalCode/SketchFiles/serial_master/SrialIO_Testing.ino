#include <Arduino.h>
#include <ctype.h>
#include <Actuator.h>

char c = 0;
int a=0, b =0, flag =0, space_index1, space_index2, com_index, e=0, d =0;
int analogPins[16] = {54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69};
int pwmPins[13] = {2,3,5,6,7,8,9,10,11,12,44,45,46};

float gearRatios[3] = {53.393,238.235,424.827};
//array[6] = {wrist.theta.value, elbow.theta.value, shoulder.theta.value, wrist.fi.value, elbow.fi.value, shoulder.fi.value};
int minHallValues[6] = {0,0,0,0,0,0}; 
int maxHallValues[6] = {1023,1023,1023,1023,1023,1023};

joint wrist(pwmPins[0],pwmPins[1],analogPins[0],pwmPins[2],pwmPins[3],analogPins[2]); 
joint elbow(pwmPins[4],pwmPins[5],analogPins[4],pwmPins[6],pwmPins[7],analogPins[6]); 
joint shoulder(pwmPins[8],pwmPins[9],analogPins[8],pwmPins[10],pwmPins[11],analogPins[10]);
joint joints[3] = {wrist, elbow, shoulder};

void setup() 
{
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
    Serial.begin(9600);
}

void loop()
{
  serial_input();
}

void serial_input()
{
  String cr, angle1, angle2, angle3, angle4, set1, set2;
  while(Serial.available()>0)
  {
    delay(3);
    c = Serial.read();
    cr +=c;
  }//Serial.println(cr);
  if(cr.length()>1)
  { 
      com_index = cr.indexOf(',');

      for(int i =0; i<cr.length(); i++)
      {
        if(i<com_index)
        set1 += cr[i];

        else if(i>com_index)
        set2 += cr[i];      
      }

      space_index1 = set1.indexOf(' ');
      space_index2 = set2.indexOf(' ');

      for (int i=0; i<set1.length(); i++)
      {
        if (i<space_index1)
        angle1+= set1[i];

        else if(i>space_index1)
        angle2+= set1[i];
      }
      
      for (int i=0; i<set2.length(); i++)
      {
        if (i<space_index2)
        angle3+= set2[i];

        else if(i>space_index2)
        angle4+= set2[i];
      } 

      a = angle1.toInt();
      b = angle2.toInt();
      d = angle3.toInt();
      e = angle4.toInt();

      move(a, b, d, e);
      Serial.print(a);
      Serial.print(',');
      Serial.print(b);
      Serial.print(',');
      Serial.print(d);
      Serial.print(',');
      Serial.println(e);
      
      a =0;
      b =0;
      d =0;
      e =0;
  }
}

void move(int wrist_theta, int wrist_fi, int elbow_theta, int elbow_fi)
{
  wrist.input(wrist_fi, wrist_theta);
  elbow.input(elbow_fi, elbow_theta);
}
