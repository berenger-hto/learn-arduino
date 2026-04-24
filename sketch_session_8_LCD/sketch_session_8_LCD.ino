#include <Wire.h>
#include <LiquidCrystalWired.h>

LiquidCrystalWired lcd(2, 16, 15, 0x3E); 

void setup() {
  lcd.init(); 
  lcd.backlight(); 

  lcd.setCursor(0, 0); 
  lcd.print("Potentiometre :"); 
}

void loop() {
  int potValue = analogRead(A0); 
  lcd.setCursor(0, 1); 
  lcd.print(potValue); 
  lcd.print("    "); 
  delay(1000); 
}
