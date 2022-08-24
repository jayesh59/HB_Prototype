//https://www.arduino.cc/en/Hacking/libraryTutorial 
// for instructions.

#include <Arduino.h>

class axis 
{
    public:

    double sun_angle;
    int R, L;
    float gear_ratio, next_a, hall_value, min_hall, max_hall;
    int current_a = 1;

    int R_PWM, L_PWM, Hall_Pin;
    float turn_angle;
    
    axis();
    float move();

};


class joint
{   
    //theta = angle with z axis
    //fi = angle with x axis on xy plain

    public:
    
    axis theta;
    axis fi;
    
    float c_theta, c_fi, c_linklength;
    // c -> current values;

    float r_theta, r_fi, r_linklength;
    // r -> required values;
    joint(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6);
    void input(float i_fi, float i_theta);
    void initiate_pins();

};
