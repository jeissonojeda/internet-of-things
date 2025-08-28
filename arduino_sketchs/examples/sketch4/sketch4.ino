int const LED1 = 13;  // LED izquierdo
int const LED2 = 12;  // LED centro
int const LED3 = 8;   // LED derecho

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // INTERMITENCIA INDIVIDUAL - LED1 (5 veces)
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
  
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
  
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
  
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
  
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(500); // Pausa entre LEDs
  
  // INTERMITENCIA INDIVIDUAL - LED2 (5 veces)
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(200);
  
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(200);
  
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(200);
  
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(200);
  
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(500); // Pausa entre LEDs
  
  // INTERMITENCIA INDIVIDUAL - LED3 (5 veces)
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(200);
  
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(200);
  
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(200);
  
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(200);
  
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(2000); 
}
