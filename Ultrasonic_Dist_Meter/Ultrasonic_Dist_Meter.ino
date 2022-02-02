#include "ThingSpeak.h"
#include "WiFi.h"

//-------Enter your WiFi Details------//
char ssid[] = "VishuMob";  //SSID
char pass[] = "7070070167@Vt";  //Password
//-----------------------------------//

const int trigger = 5; 
const int echo = 18; 
long T;
float distanceCM;

const int LEDr = 22;   //Red LED to GPIO = 21
const int LEDg = 21;  //Green LED to GPIO = 22

WiFiClient client;

//-------------ThingSpeak Details-----------------//
unsigned long myChannelField = 1487450; //Channel ID
const int ChannelField = 3; //Which channel to write data
const char * myWriteAPIKey = "8OLYPMW0FCX9SIOK"; //Your Write API Key
//-----------------------------------------------//

void setup() {
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);  
  pinMode(echo, INPUT);
  pinMode(LEDr, OUTPUT);
  pinMode(LEDg, OUTPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

}

void loop() 
{
  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
    {
      WiFi.begin(ssid,pass);
      Serial.print(".");
      delay(5000);
    }
  Serial.println("\nConnected.");
  }
  //--------------------------------------------//

  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);

//--------To Detect Danger Zone----------//
  if(distanceCM <= 20)
  {
    digitalWrite(LEDr, HIGH);   //Red LED = ON
    digitalWrite(LEDg, LOW);    //Green LED = OFF
    Serial.print("RED LED is ON\n");
  }
  else  
  {
    digitalWrite(LEDr, LOW);   //Red LED = OFF
    digitalWrite(LEDg, HIGH);  //Green LED = ON
    Serial.print("GREEN LED is ON\n");
  }
//---------------------------------------//

  ThingSpeak.writeField(myChannelField,ChannelField, distanceCM, myWriteAPIKey);
  delay(1000);
}
