#include <ESP8266WiFi.h>
const char ssid[20] = "HOMESERVER111";
const char password[20] = "123456788";
WiFiServer server(80);
int pot = A0;
float Vref = 3.3;
float resolution = Vref / 1023;
//int cnt=0;
void setup() {
    Serial.begin(115200);
    delay(10);
    
//    pinMode(ledPin, OUTPUT);
//    digitalWrite(ledPin, LOW);
pinMode(pot,INPUT);
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

void loop()
{
  float temperature = analogRead(pot);
  temperature = (temperature * resolution);
  temperature = temperature*100;
//  Serial.println(temperature);
//WiFiClient client = server.available();
//  int value = LOW;
//String request = client.readStringUntil('\r'); Serial.println(request);
//client.flush();
WiFiClient client = server.available();
//  if (!client) {
//    delay(2000);
//  }
// 
  // Wait until the client sends some data
  Serial.println("new client");
//  while(!client.available()){
//    delay(1);
//  }
   Serial.println("webpage started");
  // Read the first line of the request
//  String request = client.readStringUntil('\r');
//  Serial.println(request);
//  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
 client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Temperature SENSOR DATA</h1>");
  client.print("<h2>Server Reading:</h2>");
  client.println("<br><br>");
  
//  server.handleClient();
  client.println("temperature=");
  client.println(temperature);

  

delay(1);
Serial.println("");
  delay(200);


}
