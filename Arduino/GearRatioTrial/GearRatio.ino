int r = 0, s = 0;
int pushbutton;
int time = 0;
float r2 = 0;
  float l = 0;

int delay1()
{
//unsigned int long k;
int i,j;
unsigned int count=0;
for(i=0;i<1000;i++)
{
for(j=0;j<1000;j++)
{
if(digitalRead(8))
{
count++;
while(digitalRead(8));
}
}
}
return count;
}

void setup()
{
    pinMode(8, INPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    
  pinMode(5, OUTPUT);
  
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
   
    Serial.begin(9600);
    
}

void loop()
{
/*
    s = millis();
    //Serial.print(pushbutton);   
    if(digitalRead(8))
    {
        r++;
    }

    if(s%5000 == 0 && r>=0)
    {
        delay(1000);
        Serial.print(r*12);
        Serial.print("\n");
        r = 0;
    }

 */
l=0;
r2 = 1;
analogWrite(5, r2*255);
  analogWrite(6, l*255);
  
time=delay1();
r=(time*12);
Serial.print(r);
Serial.print("\n");
delay(5000);

}