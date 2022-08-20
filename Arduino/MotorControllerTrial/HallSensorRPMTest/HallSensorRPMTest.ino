int deg = 0;
  float r = 0;
  float l = 0;
  int flag = 0;
  int current_a = 0;
  int prev_a = 0;
  int start_a = 0;
  int count = 0;
  int flag2 = 0;

int delay1()
{
//unsigned int long k;
int i,j;
unsigned int count=0;
for(i=0;i<1000;i++)
{
for(j=0;j<1000;j++)
{
if(analogRead(A2))
{
count++;
while(analogRead(A2));
}
}
}
return count;
}

void setup() {

  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(2, HIGH);
  
}


void loop() {
r = 0;
l = 0;

analogWrite(5, r*255);
analogWrite(6, l*255);

float a = analogRead(A2);
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
  count+=1;
}
if (millis()%5000 == 0 )
{
  Serial.println(count*2);
  count = 0;
}


}
