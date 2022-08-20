#include <Servo.h>
unsigned long int t, T=465;
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  
  // put your setup code here, to run once:

}

void loop() 
{
  int c=0;
  int x=digitalRead(6);

t=millis();

 if(t<T)
 Start();
 else
 Stop(); 


 // put your main code here, to run repeatedly:

}
void Start()
{
  
  
   digitalWrite(8, LOW);
   digitalWrite(9, HIGH);
  
   
}

void Stop()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
