const int led_1 = 22;
const int buzzer = 21;

void setup() {
  pinMode(led_1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(led_1,HIGH);
  Serial.print("LED-1 is ON\n");
  delay(5000);
  digitalWrite(led_1,LOW);
  Serial.print("LED-1 is OFF\n");
  delay(1000);

  digitalWrite(buzzer,HIGH);
  Serial.print("Buzzer is ON\n");
  delay(5000);
  digitalWrite(buzzer,LOW);
  Serial.print("Buzzer is OFF\n");
  delay(1000);
}
