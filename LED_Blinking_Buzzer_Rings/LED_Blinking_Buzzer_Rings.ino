#include "ThingSpeak.h"
#include "WiFi.h"

const int led_1 = 22;
const int buzzer = 21;


/*Enter your WiFi Details*/
static char ssid[] = "tvishwajit";  //SSID
static char pass[] = "70700@Vt";  //Password


/*ThingSpeak Details*/
unsigned long myChannelField = 1491884; //Channel ID
const char * myWriteAPIKey = "ELUHHYKR9FHAXCFD"; //Your Write API Key
const int ChannelField2 = 2; //for LED-1
const int ChannelField3 = 3; //for LED-2



WiFiClient client;


void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {

  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
  }
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConnected.");
  //----------------------------------------------//
  
  
  digitalWrite(led_1,HIGH);
  Serial.print("LED-1 is ON\n");
  ThingSpeak.writeField(myChannelField,ChannelField2, led_1, myWriteAPIKey);
  delay(5000);
  
  digitalWrite(led_1,LOW);
  Serial.print("LED-1 is OFF\n");
  ThingSpeak.writeField(myChannelField,ChannelField2, led_1, myWriteAPIKey);
  delay(500);

  digitalWrite(buzzer,HIGH);
  Serial.print("Buzzer is ON\n");
  ThingSpeak.writeField(myChannelField,ChannelField3, buzzer, myWriteAPIKey);
  delay(5000);
  
  digitalWrite(buzzer,LOW);
  Serial.print("Buzzer is OFF\n");
  ThingSpeak.writeField(myChannelField,ChannelField3, buzzer, myWriteAPIKey);
  delay(500);


  //-------------Sending Data to ThingSpeak Cloud---------------//
  /*ThingSpeak.writeField(myChannelField,ChannelField2, led_1, myWriteAPIKey);
  ThingSpeak.writeField(myChannelField,ChannelField3, buzzer, myWriteAPIKey);*/
  
}
