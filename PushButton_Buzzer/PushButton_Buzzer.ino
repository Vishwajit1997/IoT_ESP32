const int BUTTON_PIN = 16; // GIOP16 pin connected to button's pin
const int BUZZER_PIN = 21; // GIOP21 pin connected to Buzzer's pin

void setup() {
  Serial.begin(115200);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set ESP32 pin to input pull-up mode
  pinMode(BUZZER_PIN, OUTPUT);       // set ESP32 pin to output mode
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // read new state

  if (buttonState == LOW) {
    Serial.println("The button is being pressed");
    digitalWrite(BUZZER_PIN, HIGH); // turn on
    delay(5000);
  }
  else
  if (buttonState == HIGH) {
    Serial.println("The button is unpressed");
    digitalWrite(BUZZER_PIN, LOW);  // turn off
  }
}
