//https://www.arduino.cc/en/Hacking/libraryTutorial 
// for instructions.

#include <Arduino.h>
#include <Actuator.h>
#include <math.h>

const float pi = 3.14159265;

axis :: axis()
{
    turn_angle = 0;
}

float axis :: move()
    {
        int flag = 0, new_angle = 0;

        if(turn_angle<0)
        {
            L = 255;
            R = 0;
            turn_angle = -1*turn_angle;
            flag = 1;
        }

        else if(turn_angle>0)
        {
            R = 255;
            L = 0;
        }

        else
            return 0;

        for(sun_angle = 0; sun_angle<=turn_angle;)
        {
            float PWM_Coeff = 0, deg = 0;
            
            deg = (sun_angle/turn_angle)*90;
            deg = deg*pi/180;

            PWM_Coeff = max(0.5,cos(deg));

            //output the motor commands.
            analogWrite(R_PWM, PWM_Coeff*R);
            analogWrite(L_PWM, PWM_Coeff*L);
            
            hall_value = analogRead(Hall_Pin);
            hall_value = (hall_value-min_hall)/(max_hall-min_hall);

            if(hall_value<0.5)
            {
                hall_value=0;
                next_a = hall_value;
            }

            else if(hall_value>=0.5)
            {
                hall_value = 1;
                next_a = hall_value;
            }

            if(current_a != next_a)
            {
                current_a = next_a;
                sun_angle += (60/gear_ratio);
            }
            /* Debuging Helpers
                Serial.print(hall_value);
                Serial.print(';');
                Serial.print(PWM_Coeff);
                Serial.print(';');
                Serial.print(R);
                Serial.print(';');
                Serial.print(L);
                Serial.print(';');
                Serial.println(sun_angle);
            */
        }

        analogWrite(R_PWM, 0);
        analogWrite(L_PWM, 0);

        if (flag == 1)
        {
            new_angle = -1*turn_angle;
            turn_angle = 0;
        }

        else 
        {
            new_angle = turn_angle;
            turn_angle = 0;
        }

        return new_angle;
    }

joint :: joint(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
{
    //c_theta = 0;
    //c_fi = 0;
    c_linklength = 0;

    theta.R_PWM = pin1;
    theta.L_PWM = pin2;
    theta.Hall_Pin = pin3;
    
    fi.R_PWM = pin4;
    fi.L_PWM = pin5;
    fi.Hall_Pin = pin6;
}

void joint :: initiate_pins()
{
    pinMode(theta.R_PWM, OUTPUT);
    pinMode(theta.L_PWM, OUTPUT);
    pinMode(theta.Hall_Pin, INPUT);

    pinMode(fi.R_PWM, OUTPUT);
    pinMode(fi.L_PWM, OUTPUT);
    pinMode(fi.Hall_Pin, INPUT);
}

void joint :: input(float i_fi, float i_theta)
{
    r_theta = i_theta;
    r_fi = i_fi;

    theta.turn_angle = r_theta - c_theta;
    fi.turn_angle = r_fi - c_fi;

    if((theta.turn_angle/(60/theta.gear_ratio)) >=1)
        c_theta += theta.move();
    
    if((fi.turn_angle/(60/fi.gear_ratio)) >=1)
        c_fi += fi.move();
}