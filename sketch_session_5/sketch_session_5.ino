#define DEL_PIN 9

void setup() {
  Serial.begin(9600); 
  pinMode(DEL_PIN, OUTPUT); 
}

void loop() {
  int potentiometerValue = analogRead(A0);
  Serial.print("Potentiometer : "); 
  Serial.println(potentiometerValue);
  byte delIntensity = potentiometerValue / 4; 
  Serial.print("DEL : "); 
  Serial.println(delIntensity);
  analogWrite(DEL_PIN, delIntensity); 
  delay(1000); 
}
