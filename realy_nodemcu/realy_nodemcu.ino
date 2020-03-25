void setup()
{
Serial.begin(9600); //baud rate for serial monitor
pinMode(D4, OUTPUT); //declare the pinMode
}
void loop()
{
digitalWrite(D4,HIGH); //Relay Off
Serial.println("Relay off");
delay(4000); //Delay fo 4 sec
digitalWrite(D4,LOW); //Relay On
Serial.println("Relay on");
delay(4000); //Delay of 4 sec
}
