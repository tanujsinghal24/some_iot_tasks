#include <ESP8266WiFi.h>
const int trigP = D1; //D4
const int echoP = D2; //D3
long duration;
float distance;
int en1=D6;
int en2=D7;
void setup() {
pinMode(trigP, OUTPUT); // Sets the trigPin as an Output
pinMode(echoP, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Open serial channel at 9600 baud rate
}
void loop() {
digitalWrite(trigP, LOW); // Makes trigPin low
delayMicroseconds(2); // 2 micro second delay
digitalWrite(trigP, HIGH); // tigPin high
delayMicroseconds(10); // trigPin high for 10 micro  seconds
digitalWrite(trigP, LOW); // trigPin low
//Nodemcu HC-SR04
//Vin Vcc
//D3 Trig
//D4 Echo
//GND GND

duration = pulseIn(echoP, HIGH); //Read echo pin, time in microseconds
distance= duration*0.034/2; //Calculating actual/real distance
Serial.print("Distance = "); //Output distance on  arduino serial monitor
Serial.println(distance);
//delay(500);
if(distance>400)
{distance=400;}
distance=distance/100;
//intx=distance;
float vl= 0.25642449+0.79570074*(distance)-0.220585*(distance*distance)+ 0.02222868*(distance*distance*distance)+1.500;
float vr=-0.02069927+ 1.25771138*(distance) -0.42779086*(distance*distance)+0.04796109*(distance*distance*distance)+1.500;
vl=vl*100;
vr=vr*100;
if(distance<0.6){vl=900;vr=500;}
else{vl=900;vr=900;}
 Serial.print("vl = "); //Output distance on  arduino serial monitor
Serial.println(vl);
Serial.print("vr = "); //Output distance on  arduino serial monitor
Serial.println(vr);
analogWrite(en1,int(vl));
analogWrite(en2,int(vr));

}
