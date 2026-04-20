#define LED_PIN 13
#define BTN_PIN 12

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BTN_PIN, INPUT); 
}

void loop() { 
  static int ledState = LOW;
  static int etatBoutonActuel = LOW;
  static int dernierEtatBouton = LOW;
  etatBoutonActuel = digitalRead(BTN_PIN); 
  if (etatBoutonActuel != dernierEtatBouton && etatBoutonActuel == HIGH) {
    ledState = !ledState; 
    digitalWrite(LED_PIN, ledState); 
    delay(50); 
  }
  dernierEtatBouton = etatBoutonActuel;
  // put your main code here, to run repeatedly:
  
}

