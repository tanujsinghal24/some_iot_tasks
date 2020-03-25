//int state;
//int flag=0;
//void setup()
//{
//pinMode(7,OUTPUT); pinMode(8,OUTPUT); Serial.begin(9600);
//}
//void loop() {
//if( Serial.available() > 0)
//{
//state = Serial.read(); Serial.println(state); flag=0;
//}
//if (state == '1') // Checking Command from User
//{
//if(flag == 0){
//Serial.println("Stop"); flag=1;
//}
//}
//else if (state == '2')
//{
//if(flag == 0)
//{
//Serial.println("Forward"); flag=1;
//Serial.println(flag);
//}}}
#include <SoftwareSerial.h>
SoftwareSerial EEBlue(10, 11); // RX | TX
void setup()
{
Serial.begin(9600);
EEBlue.begin(9600); //Default Baud for comm, it may be different for your Module.
Serial.println("The bluetooth Module.");
}

void loop()
{

// Feed any data from bluetooth to Terminal.
if (EEBlue.available())
Serial.write(EEBlue.read());

// Feed all data from termial to bluetooth
if (Serial.available())
EEBlue.write(Serial.read());}
