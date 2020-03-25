#include <ESP8266WiFi.h>
const int trigP = D3; //D4
const int echoP = D4; //D3
long duration;
int distance;
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
delay(3000); //Pause for 3 seconds and start measuring distance again
}
