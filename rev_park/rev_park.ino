//u#include <ESP8266WiFi.h>
int Red=D6;
int Blue=D8;
int Green=D7;
int buzzer=D2;
const int trigP = D4; 
const int echoP = D3;
//WiFiServer server(80)
float distance;
long duration;
void setup() {
    Serial.begin(115200);
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
  digitalWrite(buzzer, LOW);
  digitalWrite(trigP, LOW); 
delayMicroseconds(2);
digitalWrite(trigP, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigP, LOW); 
long duration = pulseIn(echoP, HIGH); 
float distance= (duration*0.034)/2; 
Serial.print("Distance = ");
Serial.println(distance);
//distance/=100;

  if (distance>=10) 
   {
      analogWrite(Red,0);
      analogWrite(Green,0);
      analogWrite(Blue,1023);
      Serial.println("rgb(230,130,238) ON");
      
   }
  if (distance>=8 && distance<10) 
   {
      analogWrite(Red,521);
      analogWrite(Green,0);
      analogWrite(Blue,300);
      Serial.println("rgb(75,0,130) ON");
   }

  if (distance>=6 && distance<8) 
   {
      analogWrite(Red,1023);
      analogWrite(Green,0);
      analogWrite(Blue,0);
      Serial.println("blue rgb(0,0,255) ON");
   }
  if (distance>=4 && distance<6) 
   {
      analogWrite(Red,0);
      analogWrite(Green,1023);
      analogWrite(Blue,0);
      Serial.println("green rgb(0,255,0) ON");
   }
  if (distance>=2 && distance<4) 
   {
      analogWrite(Red,204);
      analogWrite(Green,1023);
      analogWrite(Blue,1023);
      Serial.println("yellow");
   }
     if (distance>1 && distance<2) 
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
      Serial.println(" red rgb(255,0,0) ON");

      digitalWrite(buzzer, HIGH);
   }
   delay(100);
   digitalWrite(buzzer, LOW);
}
