#include <Arduino.h>

long input_values[6];

void setup()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);
    pinMode(13, INPUT);

    Serial.begin(9600);
}

void loop()
{
    int a0 = 0, a1 = 0, a2= 0, a3 = 0, a4 = 0, a5 = 0, d1 = 0, coeff = 1;
    d1 = digitalRead(13);

    if(d1)
        coeff = -1;
   else
        coeff = 1;

    a0 = coeff*(1023 - analogRead(A0));
    a1 = coeff*(1023 - analogRead(A1));
    a2 = coeff*(1023 - analogRead(A2));
    a3 = coeff*(1023 - analogRead(A3));
    a4 = coeff*(1023 - analogRead(A4));
    a5 = coeff*(1023 - analogRead(A5));
    
    int int_arr[6] = {a0, a1, a2, a3, a4, a5};
    
    for (int i = 0; i<6;i++)
    {
        Serial.print(int_arr[i]);
        Serial.print(',');
    }
    Serial.println();
}