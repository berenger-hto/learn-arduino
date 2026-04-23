#define DEL_PIN 9
#define SECOND_DEL_PIN 13
#define INTERVAL 500

void setup() {
  Serial.begin(9600);
  pinMode(DEL_PIN, OUTPUT);
  pinMode(SECOND_DEL_PIN, OUTPUT); 
}

unsigned long prevMillis = 0; 

void loop() {
  int potentiometerValue = analogRead(A0);
  byte delIntensity = potentiometerValue / 4;
  analogWrite(DEL_PIN, delIntensity);
  unsigned long currentMillis = millis();

  if (currentMillis - prevMillis >= INTERVAL) {
    prevMillis = currentMillis; 
    digitalWrite(SECOND_DEL_PIN, !digitalRead(SECOND_DEL_PIN)); 
    /* Log */
    Serial.print("Potentiometer value: ");
    Serial.println(potentiometerValue);
    Serial.print("DEL value: ");
    Serial.println(delIntensity);
  }
}
