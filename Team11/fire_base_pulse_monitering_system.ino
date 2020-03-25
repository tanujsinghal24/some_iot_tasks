#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "pulsemonitering1sytem.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
//#define FIREBASE_AUTH "AIzaSyCPSUngs1azqz8lOfQJQD7rQ0kTLl2pKH0"
#define WIFI_SSID "rpi11"                                               //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "JB450000"                                      //Password of your wifi network 

int pin=A0; 
//int val4;

void setup() 
{
  Serial.begin(115200);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  pinMode(pin,INPUT);

  

  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST); //Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  
}

void loop() 
{
    int pulse = analogRead(pin);
    float BMP=pulse/1024.0 *120.0;
    Firebase.setString("BMP", String(int(BMP)));
    Serial.println(BMP);
    Serial.println(Firebase.failed());
//    delay(1000);
}
