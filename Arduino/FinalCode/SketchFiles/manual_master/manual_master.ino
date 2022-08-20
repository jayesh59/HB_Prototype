#include <Arduino.h>
#include <Actuator.h>
int analogPins[16] = {54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69};
int pwmPins[13] = {2,3,5,6,7,8,9,10,11,12,44,45,46};
joint wrist(pwmPins[0],pwmPins[1],analogPins[0],pwmPins[2],pwmPins[3],analogPins[2]); 
joint elbow(pwmPins[4],pwmPins[5],analogPins[4],pwmPins[6],pwmPins[7],analogPins[6]); 
joint shoulder(pwmPins[8],pwmPins[9],analogPins[8],pwmPins[10],pwmPins[11],analogPins[10]);
joint joints[3] = {wrist, elbow, shoulder};

long input_values[6] = {0,0,0,0,0,0};
long prev_input[6] = {0,0,0,0,0,0};
int r=0, l=0;
int cmd = 0;

void setup()
{
    Serial.begin(9600);
    for(int i=0; i<3; i++)
        joints[i].initiate_pins();
}

void loop()
{
    if(Serial.available())
    {
        for(int i=0;i<6;i++)
            input_values[i]=int(Serial.read());

        for(int i=0;i<6;i++)
        {
            if(prev_input[i]!=input_values[i])
            {
                if (input_values[i]<0)
                {
                    r = 0;
                    l = 1;
                    cmd = -1*input_values[i];
                }
                else if(input_values[i]>=0)
                {
                    r = 1;
                    l = 0;
                    cmd = input_values[i];
                }

                if(i%2==0)
                {
                    analogWrite(joints[i/2].theta.R_PWM, r*cmd);
                    analogWrite(joints[i/2].theta.L_PWM, l*cmd);
                }

                else
                {
                    analogWrite(joints[i/2].fi.R_PWM, r*cmd);
                    analogWrite(joints[i/2].fi.L_PWM, l*cmd);
                }

                prev_input[i] = input_values[i];
            }

            else
                continue;
        }
    }
}