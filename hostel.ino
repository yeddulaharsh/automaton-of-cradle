#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[]="UJ2EvzNWY5uqltV80jGwDk-k3zB3FyJd";

const char* ssid = "BEAM255420";                                  //fill in your wifi name
const char* password = "39923771"; 

 void setup()
{
//pinMode(sensorPin, D0);
Serial.begin(9600);
delay(10);
WiFi.begin(ssid, password);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
Serial.print("..........");
Serial.println();
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) 
delay(500);

Serial.println("WiFi connected");
Serial.println();

  Serial.begin(9600);
  Blynk.begin(auth,"ssid","password");
  //sensorReaading=analogRead(sensorPin);

  
  //const int capteur_D = 4;
const int capteur_A = A0;

int val_analogique;

 // pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
  Serial.begin(9600);
}


void loop()
{
  
int val_analogique;
//const int capteur_D = 4;
const int capteur_A = A0;

val_analogique=analogRead(capteur_A); 
 Serial.print("Analog value : ");
 Serial.println(val_analogique); 
 Serial.println("");
  delay(1000);

  Blynk.run();

if(analogRead(capteur_A)<1020) 
  {
    Serial.println("Digital value : wet"); 
    Blynk.notify("ATTENTION PLEASE..");
    delay(10); 
  }
else
  {
    Serial.println("Digital value : dry");
    delay(10); 
  }
}
