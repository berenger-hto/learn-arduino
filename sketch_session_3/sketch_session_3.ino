#define RED_DEL 11
#define ORANGE_DEL 12
#define GREEN_DEL 13

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_DEL, OUTPUT); 
  pinMode(ORANGE_DEL, OUTPUT); 
  pinMode(GREEN_DEL, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_DEL, HIGH); 
  delay(12000); 
  digitalWrite(RED_DEL, LOW); 
  digitalWrite(GREEN_DEL, HIGH); 
  delay(8000);
  digitalWrite(GREEN_DEL, LOW); 
  digitalWrite(ORANGE_DEL, HIGH); 
  delay(3000); 
  digitalWrite(ORANGE_DEL, LOW); 
  
}
