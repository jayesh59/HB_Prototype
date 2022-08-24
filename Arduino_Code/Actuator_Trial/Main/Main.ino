#include <ctype.h>
#include <Arduino.h>
#include <Actuator.h>

joint test(2,3,54, 5,6,56);
int a = 0;
void setup()
{

    test.theta.gear_ratio = 424.827;
    test.fi.gear_ratio = 424.827;
    test.initiate_pins();
    Serial.begin(9600);
    test.theta.min_hall = 100;
    test.theta.max_hall = 140;
    test.fi.min_hall = 205;
    test.fi.max_hall = 261;

Serial.begin(9600);
}

void loop()
{   
    analogWrite(2,255);
    analogWrite(3, 0);
    //a = analogRead(56);
    //Serial.println(a);
}