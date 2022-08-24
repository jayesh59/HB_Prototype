#include <Arduino.h>
#include <Wire.h>
#include <ctype.h>
#include <Servo.h>

#define RPWM_R 2
#define RPWM_L 3
#define LPWM_R 5
#define LPWM_L 6
#define Servo_R 7
#define Servo_L 8

int rec[3] = {0,0,0};
int rec_prev[3] = {0,0,0};
int i = 0;

Servo Left, Right;

void setup()
{
    pinMode(RPWM_R, OUTPUT);
    pinMode(RPWM_L, OUTPUT);
    pinMode(LPWM_R, OUTPUT);
    pinMode(LPWM_L, OUTPUT);
    pinMode(Servo_L, OUTPUT);
    pinMode(Servo_R, OUTPUT);

    Left.attach(Servo_L);
    Right.attach(Servo_R);

    Serial.begin(115200);
    Wire.begin(1);
    Wire.onReceive(callback);
}

void callback(int bytes)
{
    for (i=0;i<bytes;i++)
    {
        rec[i] = Wire.read();
    }

    for(i=0;i<bytes;i++)
    {
        if (rec_prev[i]!=rec[i])
        {
            rec_prev[i]=rec[i];
            move(rec);
        }
        else
        continue;        
    }
      
    
    for(i=0;i<bytes;i++)
    {
        Serial.print(rec[i]);
        Serial.print(',');
    }
}

void move(int dat[3])
{
    if (dat[0]>=0)
    {
        analogWrite(RPWM_L, dat[0]);
        analogWrite(RPWM_R, 0);
    }
    else if (dat[0]<0)
    {
        analogWrite(RPWM_L, 0);
        analogWrite(RPWM_R, -dat[0]);
    }
    

    if (dat[1]>=0)
    {
        analogWrite(RPWM_L, dat[1]);
        analogWrite(RPWM_R, 0);
    }
    else if (rec[1]<0)
    {
        analogWrite(RPWM_L, 0);
        analogWrite(RPWM_R, -dat[1]);
    }

    int r_angle = 180-rec[2];
    Left.write(rec[2]);
    Right.write(r_angle);
    Serial.println(r_angle);
}

void loop()
{

}