//#include <ESP8266WiFi.h>
int Red=D6;
int Blue=D8;
int Green=D7;
int buzzer=D1;
const int trigP = D4; 
const int echoP = D3;
//WiFiServer server(80);
long duration;
float distance;
void setup() {
    Serial.begin(9600);
    delay(10);
    pinMode(trigP, OUTPUT); 
    pinMode(echoP, INPUT); 
    pinMode(Red, OUTPUT);
    pinMode(Blue, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(buzzer, OUTPUT);
//    pinMode();
//    digitalWrite(ledPin, LOW);
}
void loop() {
  digitalWrite(trigP, LOW); 
delayMicroseconds(2);
digitalWrite(trigP, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigP, LOW); 
long duration = pulseIn(echoP, HIGH); 
float distance= duration*0.034/2; 
Serial.print("Distance = ");
Serial.println(distance);

  if (distance>=8) 
   {
      analogWrite(Red,923);
      analogWrite(Green,522);
      analogWrite(Blue,923);
      Serial.println("rgb(238,130,238) ON");
   }
  if (distance>=7 && distance<8) 
   {
      analogWrite(Red,522);
      analogWrite(Green,0);
      analogWrite(Blue,300);
      Serial.println("rgb(75,0,130) ON");
   }

  if (distance>=6 && distance<7) 
   {
      analogWrite(Red,0);
      analogWrite(Green,0);
      analogWrite(Blue,1023);
      Serial.println("rgb(0,0,255) ON");
   }
  if (distance>=4 && distance<6) 
   {
      analogWrite(Red,0);
      analogWrite(Green,1023);
      analogWrite(Blue,0);
      Serial.println("rgb(0,255,0) ON");
   }
  if (distance>=2 && distance<4) 
   {
      analogWrite(Red,0);
      analogWrite(Green,1023);
      analogWrite(Blue,1023);
      Serial.println("rgb(255,255,0) ON");
   }
     if (distance>=1 && distance<=2) 
   {
      analogWrite(Red,0);
      analogWrite(Green,510);
      analogWrite(Blue,1023);
      Serial.println("rgb(255,127,0) ON");
      digitalWrite(buzzer, HIGH);
      
   }
     if (distance<=1) 
   {
      analogWrite(Red,0);
      analogWrite(Green,0);
      analogWrite(Blue,1023);
      Serial.println("rgb(255,0,0) ON");
      digitalWrite(buzzer, HIGH);
   }
   delay(100);
   
}
