#define DEL_PIN 9
#define BTN_PIN 12
#define DEL2_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(DEL2_PIN, OUTPUT);
  pinMode(DEL_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  static unsigned long prevMillis = 0;
  unsigned long currentMillis = millis();
  static bool mode = false;
  byte ledIntensity = analogRead(A0) / 4;
  static bool prevBtnState = LOW;
  static bool btnState = HIGH;
  btnState = digitalRead(BTN_PIN);
  int loopDuration = map(analogRead(A0), 0, 1023, 50, 1000);

  if (btnState == LOW && prevBtnState != btnState) {
    delay(50);
    mode = !mode;
    digitalWrite(DEL2_PIN, mode);
  }

  prevBtnState = btnState;

  if (!mode) {
    Serial.println("Mode 1 activé !");
    analogWrite(DEL_PIN, ledIntensity);
    Serial.print("Led intensity = ");
    Serial.println(ledIntensity);
  }

  if (mode && currentMillis - prevMillis >= loopDuration) {
    prevMillis = currentMillis;
    Serial.println("Mode 2 activé !");
    digitalWrite(DEL_PIN, !digitalRead(DEL_PIN));
    Serial.print("Loop duration");
    Serial.println(loopDuration);
  }
}
