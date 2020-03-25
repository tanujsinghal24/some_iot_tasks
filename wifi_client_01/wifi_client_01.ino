
#include <SPI.h>
#include <ESP8266WiFi.h>

byte ledPin = 2;
int pin=A0;
char ssid[] = "Oneplus_7p";           // SSID of your home WiFi
char pass[] = "12345678";            // password of your home WiFi
int a =0;
unsigned long askTimer = 0;

IPAddress server(192,168,43,223);       // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(115200);               // only for debug
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  pinMode(ledPin, OUTPUT);
  pinMode(pin, INPUT);
}

void loop () {
  client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  int temp=analogRead(pin);
  client.print("Temp from Client 1--- ");  // sends the message to the server
  client.println(temp);
  
  //a++;
 // client.println(a);  // sends the message to the server

 String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println(answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
  delay(2000);                  // client will trigger the communication after two seconds
}
