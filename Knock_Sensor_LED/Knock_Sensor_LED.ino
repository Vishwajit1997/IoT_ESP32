int Led = 13 ;// Declaration of the LED output pin
int Sensor = 10; // Declaration of the sensor input pin
int val; // Temporary variable
   
void setup ()
{
  Serial.begin(115200);
  delay(100);
  pinMode (Led, OUTPUT) ; // Initialization output pin
  pinMode (Sensor, INPUT) ; // Initialization sensor pin
  Serial.print("Setup is Done\n");
}
   
void loop ()
{
  val = digitalRead (Sensor) ; // The current signal at the sensor will be read
   
  if (val == HIGH) // If a signal was detected , the LED will light up
  {
    digitalWrite (Led, LOW);
    Serial.print("No Shock detected\n");
  }
  else
  {
    digitalWrite (Led, HIGH);
    Serial.println("Shock is Detected\nLED is ON\n");
  }
}
