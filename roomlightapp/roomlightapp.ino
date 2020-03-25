#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const int Red = D6;
const int Green = D7;
const int Blue = D8;
const char* ssid = "HOMESERVER111";
const char* password = "123456789";
//const char ssid[20] = "ONEPLUS_7p";
//const char password[20] = "12345678";
// Set web server port number to 80
WiFiServer server(80);

void setup() {
    Serial.begin(115200);
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
//  Serial.begin(115200);
//  delay(10);
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//    Serial.println("");
//    Serial.println("WiFi connected");
//    // Start the server
//    server.begin();
//    Serial.println("Server started");
//    Serial.print("Use this URL to connect: ");
//    Serial.print("http://");
//    Serial.print(WiFi.localIP());
//    Serial.println("/");
  pinMode(Red,OUTPUT);
    pinMode(Green,OUTPUT);
    pinMode(Blue,OUTPUT);
}
void loop(){

 int posr=-1;
 int posg=-1;
 int pos2=-1;
WiFiClient client = server.available(); 
  while(!client.available()){delay(1);}
if (client) { // If a new clientconnects,
Serial.println("New Client."); // print a message outin the serial port
String currentLine = ""; // make a String tohold incoming data from the client
while (client.connected()) { // loop while theclient's connected
if (client.available()) { 


String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
Serial.println(request);
posr = request.indexOf('r');
posg=request.indexOf('g');
pos2 = request.indexOf('e');
Serial.println("main loop");
if (posr!=-1){
String s = request.substring(posr+1, pos2);
int x = s.toInt();
Serial.println(s);
analogWrite(Red,1023);
analogWrite(Green,1023);
analogWrite(Blue,x);
Serial.println(x);
//digitalWrite(Red,HIGH);
//digitalWrite(Green,LOW);
//digitalWrite(Blue,LOW);
//Serial.println("red up");
}
if (posg!=-1){
String s = request.substring(posg+1, pos2);

int x = s.toInt();
//analogWrite(Red,x);
//analogWrite(Green,1023);
//analogWrite(Blue,1023);
digitalWrite(Red,HIGH);
digitalWrite(Green,LOW);
digitalWrite(Blue,LOW);
Serial.println("green up");
Serial.println(x);
}

Serial.println("Client disconnected.");
Serial.println("");
//}
}
}}
}
