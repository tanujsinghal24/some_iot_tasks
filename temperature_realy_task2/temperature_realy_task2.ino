#include <ESP8266WiFi.h>
const char ssid[20] = "ONEPLUS_7p";
const char password[20] = "12345678";
WiFiServer server(80);
int pot = A0;
int ledPin=D2;
int ledPin2=D3;
float Vref = 3.3;
float resolution = Vref / 1023;
int cnt=0;
void setup() {
  Serial.begin(115200);
  delay(10);
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
    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
    //Serial.begin(9600);
    pinMode(pot, INPUT);
//    pinMode(irPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  }
}

void loop()
{
  float temperature = analogRead(A0);
  temperature = (temperature * resolution);
  temperature = temperature*100;
  Serial.println(temperature);
WiFiClient client = server.available();
  int value = LOW;
String request = client.readStringUntil('\r'); Serial.println(request);
client.flush();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
 client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Temperature SENSOR DATA</h1>");
  client.print("<h2>Server Reading:</h2>");
  client.println("<br><br>");
  
  //server.handleClient();
  client.println("temperature=");
  client.println(temperature);
  client.print("Led is now: "); 
  
  if(temperature>=23){
    digitalWrite(ledPin2, HIGH);
    tone(D3, 1, 100);
    delay(1000);
    }digitalWrite(ledPin2, LOW);
//digitalWrite(ledPin, HIGH);
if (request.indexOf("/R=ON") != -1) {
  digitalWrite(ledPin, HIGH);
value = HIGH;
}
if (request.indexOf("/R=OFF") != -1) 
{
digitalWrite(ledPin, LOW);
value = LOW;
}
if(value == HIGH) {
client.print("On"); } else {
client.print("Off"); }
client.println("<br><br>");
client.println("<a href=\"/R=ON\"\"><button>On </button></a>"); client.println("<a href=\"/R=OFF\"\"><button>Off </button></a><br />"); client.println("</html>");
delay(1);
Serial.println("Client disonnected"); Serial.println("");
  delay(200);


}
