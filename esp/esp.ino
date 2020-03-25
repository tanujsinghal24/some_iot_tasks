#include <ESP8266WiFi.h>
const char ssid[20] = "ONEPLUS_7p";
const char password[20] = "12345678";
WiFiServer server(80);
String rx_byte ="";
String inString="";
void setup() {
Serial.begin(115200);
delay(10);
pinMode(ledPin, OUTPUT);
//digitalWrite(ledPin, LOW);
// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
Serial.println("");
Serial.println("WiFi connected");
// Start the server
server.begin();
Serial.println("Server started");
// Print the IP address
Serial.print("Use this URL to connect: ");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");


}


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

server.handleClient();
client.println(data);
  Serial.println(data);
  delay(200);

  inString="";
  }
}
}
