#include <ESP8266WiFi.h>
const char ssid[20] = "HOMESERVER11";
const char password[20] = "12345678";
WiFiServer server(80);
String rx_byte ="";
String inString="";
void setup() {
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

// Check if a client has connected
WiFiClient client = server.available();
if (!client) {
return;
}
// Wait until the client sends some data
Serial.println("new client");
while(!client.available()){
delay(1);
}


int inChar=Serial.read();
if(isDigit(inChar)){
 inString+=(char)inChar;
}
if(inChar=='\n'){
int data=inString.toInt();
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<h1>ESP8266 WEB SERVER</h1>");
client.print("<h2>Server Reading:</h2>");
client.println("<br><br>");

//server.handleClient();
client.println(data);
  Serial.println(data);
  delay(200);

  inString="";

}
}
