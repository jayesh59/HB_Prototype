#include <TM1637Display.h>
#include <RTClib.h>
#include <Wire.h>
RTC_DS3231 rtc;
#define CLK 9
#define DIO 10
TM1637Display display(CLK, DIO);

void setup()
{
  Wire.begin();
  rtc.begin();
  pinMode(2, OUTPUT);//for LEDs
  pinMode(3, OUTPUT);//for LEDs
  digitalWrite(3, LOW);//Ground
  digitalWrite(2, HIGH);//Vcc
  digitalWrite(8, HIGH);//for vcc of tm1637
  pinMode(8,OUTPUT);//for vcc of tm1637
  digitalWrite(7, LOW);//for grn of tm1637
  pinMode(7,OUTPUT);//for grn of tm1637
  pinMode(10, OUTPUT);//for DIO of tm1637
  pinMode(9, OUTPUT);//for CLK of tm1637
  pinMode(6, OUTPUT);//for motor driver
  pinMode(5, OUTPUT);//for motor driver
  pinMode(13, OUTPUT);//for rtc
  digitalWrite(13,LOW);//Ground
  pinMode(4,OUTPUT);//for rtc
  digitalWrite(4,HIGH);//for rtc vcc                  
  display.setBrightness(13);//brightness of display(8 to 15)
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop() 
{
    int x; 
    DateTime now=rtc.now();
    display.showNumberDec(now.hour(),false,2,0);//for display of hourson screen
    display.showNumberDec(now.minute(),false,2,2);//for display of minutes on screen
    Zero();
    Colon();
    Reset();
  
   if(now.hour()==6 && now.minute()==30 && now.second()<1 && (millis()%1000)<(600+(2*x)))//for morning
   {
    x+=30;
    Reverse();
   }
   
   else if(now.hour()==14 && now.minute()==15 && now.second()<1 && (millis()%1000)<(300+x))//for evening
   {
    x+=30;
    Start();
   }
   
   else if(now.hour()==20 && now.minute()==30 && now.second()<1 && (millis()%1000)<(300+x))//for night
   {
    x+=30;
    Start();
   }
   
   else
   Stop();

}


void Start()//for motor rotation
{ 
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}

void Stop()//for motor stop
{
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
}

void Zero()//for zero display
{
    DateTime now=rtc.now();
    if(now.minute()<10)
    display.showNumberDec(0,false,1,2);//for display of 0 before single minutes on screen
    if(now.hour()<10)
    display.showNumberDec(0,false,1,0);//for display of 0 before single hours on screen
}

void Colon()//for colon display
{
 if((millis()%1000)<=500)
 display.setColon(true);
 else if((millis()%1000)>500)
 display.setColon(false);//for blinking colon
}

void Reverse()//For Reverse Rotation... accountability for delta in every rotation
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}

void Reset()// to reset rotation delta factor
{
  int x;
  if(millis()==0)
  x=0;
}
