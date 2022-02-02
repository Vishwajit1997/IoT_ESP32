#include "ThingSpeak.h"
#include <WiFi.h>

//-------Enter your WiFi Details------//
const char* ssid = "VishuMob";  //SSID
const char* password = "7070070167@Vt";  //Password
//-----------------------------------//

WiFiClient client;

//-------------ThingSpeak Details-----------------//
unsigned long myChannelNumber = 1491884; //Channel ID
const char * myWriteAPIKey = "ELUHHYKR9FHAXCFD"; //Your Write API Key
int field_id = 1; //Which channel to write data
//-----------------------------------------------//

int led = 22;   //The pin that the LED is atteched to
int buzzer = 21;  //The pin that the Buzzer is atteched to
int sensor = 12; //12;  //The pin that the Sensor is atteched to
int state = LOW;  //By default, no motion detected
int val = 0;      //variable to store the sensor status (value)

void setup() {
  pinMode(led,OUTPUT);   //Initialize LED as an OUTPUT
  pinMode(buzzer, OUTPUT);  //Initialize Buzzer as an OUTPUT
  pinMode(sensor,INPUT); //Initialize Sensor as an INPUT
  Serial.begin(115200);   //Initialize Serial Monitor
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);   //Intialize ThingSpeak
}

void loop() {
  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
    {
      WiFi.begin(ssid,password);
      Serial.print("Searching for WiFi...\n");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  //--------------------------------------------//
  
  val = digitalRead(sensor);  //read sensor value

  if(val == HIGH)    //check if sensor is HIGH
  {
    Serial.print("\nPIR Sensor is ");
    Serial.println(val);
    digitalWrite(led, HIGH);  //turn LED ON
    digitalWrite(buzzer, HIGH);  //turn Buzzer ON
    Serial.print("\tLED is ON");
    Serial.print("\tBuzzer is ON");
    ThingSpeak.writeField(myChannelNumber, field_id, val, myWriteAPIKey);
    delay(2000);
   }
   
   if(val == LOW)    //check if the sensor is LOW
   {
    Serial.print("\nPIR Sensor is ");
    Serial.println(val);
    digitalWrite(led, LOW);   //turn LED OFF
    digitalWrite(buzzer, LOW);  //turn Buzzer OFF
    Serial.print("\tLED is OFF");
    Serial.print("\tBuzzer is OFF");
    ThingSpeak.writeField(myChannelNumber, field_id, val, myWriteAPIKey);
    delay(500);
   }
}
