#define DEL_PIN 9
#define BUTTON_PIN 12

int incrementIntensity(int level) {
  switch (level) {
    case 0: return 80;
    case 80: return 160;
    case 160: return 255;
    default: return 0; 
  }
}

void setup() {
  Serial.begin(9600); 
  pinMode(DEL_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  static int ledState = 0;
  static bool buttonState = LOW;
  static bool lastButtonState = LOW; 
  buttonState = digitalRead(BUTTON_PIN); 

  if (buttonState == HIGH && buttonState != lastButtonState) {
    ledState = incrementIntensity(ledState);
    Serial.print("Niveau actuel : ");
    Serial.println(ledState);
    analogWrite(DEL_PIN, ledState); 
    delay(50); 
  }
  lastButtonState = buttonState;
}
