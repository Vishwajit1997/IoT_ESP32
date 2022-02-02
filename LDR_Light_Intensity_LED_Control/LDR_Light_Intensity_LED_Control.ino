#define Light 2
#define led 22


void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(Light,INPUT);
  pinMode(led,OUTPUT);
  Serial.print("Setup Done\n");
} 

void loop() {
  int val = analogRead(Light);

  if(val > 1000)
  {
    digitalWrite(led,LOW);
    Serial.println(val);
    Serial.print("More LIGHT\n");
    Serial.print("Keeping LED OFF\n");
  }
  else
  {
    digitalWrite(led,HIGH);
    Serial.println(val);
    Serial.print("LOW LIGHT\n");
    Serial.print("Switching ON the LED\n");
  }

}
