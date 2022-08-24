int deg = 0;
  float r = 0;
  float l = 0;
  int flag = 0;
  float current_a = 0;
  float prev_a = 1;
  float start_a = 0;
  
void setup() 
{
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  
}

void loop() 
{
  
  
  float a = analogRead(A2);  
  if (millis() == 0)
  {
    if(a<= 350)
    {
      a = 0;    
    }

    else if(a>= 351)
    {
      a = 1;
    }
    start_a = a;
    prev_a = start_a;
    //flag = 1;
  }
if (1)
{
  l = 0;
  r = 0.5;
  //analogWrite(5, r*255);
  //analogWrite(6, l*255);
  a  = analogRead(A2);
  Serial.println(a);
  //delay(500);
  a = (a-420)/40;
if(a<0.5)
{
  a=0;
  current_a = a;
}

else if(a>=0.5)
{
a = 1;
  current_a = a;
}

if(prev_a != current_a)
{
  prev_a = current_a;
  deg += 60;
  //Serial.println(deg);
  //count+=1;
}
  
  //Serial.println(a);
  
 
  //delay(200);
}
else
{
  l = 0;
  r = 0;
  analogWrite(5, r*255);
  analogWrite(6, l*255);
}
}
