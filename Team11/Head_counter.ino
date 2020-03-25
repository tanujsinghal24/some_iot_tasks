#include <ESP8266WiFi.h>
const char ssid[20] = "Team11";
const char password[20] = "12345678";
WiFiServer server(80);
String rx_byte ="";
String inString="";

int irPin1 = D2;
float counter1 = 0;
int laststate1 = HIGH;
int irPin2 = D3;
float counter2 = 0;
int laststate2 = HIGH;
int c1;
int c2;
void setup(){
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
// Print the IP address
Serial.print("Use this URL to connect: ");
Serial.print("http://");
Serial.print(WiFi.localIP());
Serial.println("/");
//Serial.begin(9600);
pinMode(irPin1, INPUT);
pinMode(irPin2, INPUT);
}
}

void loop()
{
  float state1 = digitalRead(irPin1);
  float state2 = digitalRead(irPin2);
  if ( state1 != laststate1) 
  {
     laststate1 = state1;
     counter1=counter1+0.5;
     if(counter1-int(counter1)==0)
      {Serial.print("counter1 =");
     Serial.println(int(counter1));
      c1=int(counter1);
     }
  }
    if ( state2 != laststate2) 
  {
     laststate2 = state2;
     counter2=counter2+0.5;
     if(counter2-int(counter2)==0)
      {Serial.print("counter2 =");
     Serial.println(int(counter2));
     c2=int(counter2);
     }
  }
  WiFiClient client = server.available();

client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println(""); // do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<h1>IR SENSOR DATA</h1>");
client.print("<h2>Server Reading:</h2>");
client.println("<br><br>");

//server.handleClient();
client.println("Entry=");
client.println(c1);
client.println("Exit=");
client.println(c2);
  delay(200);

  inString="";

}
