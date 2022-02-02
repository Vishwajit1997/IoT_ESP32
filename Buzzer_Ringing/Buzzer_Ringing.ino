const int buzzer = 21;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  Serial.begin(115200);
  
  //Inside Setup() function Buzzer will ring once
  /*digitalWrite(buzzer,HIGH);
  Serial.print("Buzzer is ON\n");
  delay(6000);
  digitalWrite(buzzer,LOW);
  Serial.print("Buzzer is OFF\n");
  delay(4000);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  //Inside Loop()function, Buzzer will rings repeatedly
  digitalWrite(buzzer,HIGH);
  Serial.print("Buzzer is ON\n");
  delay(6000);
  digitalWrite(buzzer,LOW);
  Serial.print("Buzzer is OFF\n");
  delay(4000);
}
