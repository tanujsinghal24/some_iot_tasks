#include <ESP8266WiFi.h>

const char ssid[20] = "HomeServer11";
const char password[20] = "12345678";
int ledPin = 2; // GPIO 2
int Red=D6;
int Blue=D8;
int Green=D7;
WiFiServer server(80);

void setup() {
    Serial.begin(115200);
    delay(10);
    
    pinMode(Red, OUTPUT);
    pinMode(Blue, OUTPUT);
    pinMode(Green, OUTPUT);
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, LOW);

    delay(5000);
    Serial.println("");
    Serial.println("Server-------------------------------");
    Serial.print("Configuring access point");
    WiFi.mode(WIFI_AP);           
    WiFi.softAP(ssid, password);
    //WiFi.begin(ssid, password);

    Serial.println("");
    Serial.print("Hotspot Created : ");
    Serial.println(WiFi.softAPIP());

  // Start the server
    server.begin();
    Serial.println("Server started");
    Serial.println("-------------------------------------");
    Serial.println("");
}
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if (request.indexOf("/W")!=-1) 
   {
      digitalWrite(Red,HIGH);
      digitalWrite(Green,HIGH);
      digitalWrite(Blue,HIGH);
      Serial.println("White LED ON");
   }
   if (request.indexOf("/R")!=-1) 
   {
      digitalWrite(Red,HIGH);
      digitalWrite(Green,LOW);
      digitalWrite(Blue,LOW);
      Serial.println("Red LED ON");
   }
   if (request.indexOf("/G")!=-1) 
   {
      digitalWrite(Red,LOW);
      digitalWrite(Green,HIGH);
      digitalWrite(Blue,LOW);
      Serial.println("Green LED ON");
   }
   if (request.indexOf("/B")!=-1) 
   {
      digitalWrite(Red,LOW);
      digitalWrite(Green,LOW);
      digitalWrite(Blue,HIGH);
      Serial.println("BLUE LED ON");
   }
   if (request.indexOf("/O")!=-1) 
   {
      digitalWrite(Red,LOW);
      digitalWrite(Green,LOW);
      digitalWrite(Blue,LOW);
      Serial.println("NO LED ON");
   }
}
