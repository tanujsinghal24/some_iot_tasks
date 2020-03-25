#include <FirebaseArduino.h>
#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "distance-finder-353a6.firebaseio.com"
#define WIFI_SSID "my_empire" // Change the name of your WIFI
#define WIFI_PASSWORD "@myempire" // Change the password of your WIFI

int outputpin = A0;
int analogValue;
float millivolts,celsius;

void setup() 
{
   Serial.begin(115200);        // Open serial channel at 115200 baud rate  
   pinMode(outputpin, INPUT);
   
   WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
   Serial.print("connecting");
   while (WiFi.status()!=WL_CONNECTED)
   {
      Serial.print(".");  
      delay(500);
   }
   Serial.println();
   Serial.print("connected:");
   Serial.println(WiFi.localIP());

   Firebase.begin(FIREBASE_HOST); 
}

void loop() 
{ 
  analogValue = analogRead(outputpin);
  millivolts = (analogValue/1024.0) * 3300;     //3300 is the voltage provided by NodeMCU
  celsius = millivolts/10;
  String Value = String(celsius)+ String(" °C");
  
  Serial.print("Temperature = ");        //Output distance on arduino serial monitor 
  Serial.println(Value);
  
  Firebase.setString("SensorValue",Value);
  delay(200);
}
