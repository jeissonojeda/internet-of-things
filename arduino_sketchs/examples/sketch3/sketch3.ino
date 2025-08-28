int const LED1 = 13;  // LED izquierdo
int const LED2 = 12;  // LED centro
int const LED3 = 8;   // LED derecho

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // SERIE EN CÍRCULO
  
 
  digitalWrite(LED1, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  
  digitalWrite(LED2, HIGH);
  delay(400);
  digitalWrite(LED2, LOW);
  
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED3, LOW);
  
 
  digitalWrite(LED3, HIGH);
  delay(400);
  digitalWrite(LED3, LOW);
  
  digitalWrite(LED2, HIGH);
  delay(400);
  digitalWrite(LED2, LOW);
  
  digitalWrite(LED1, HIGH);
  delay(400);
  digitalWrite(LED1, LOW);
  
  // Pausa antes de repetir
  delay(500);
}
