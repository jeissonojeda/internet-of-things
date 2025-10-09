int const LED1 = 13;  // LED ROJO
int const LED2 = 12;  // LED AMARILLO
int const LED3 = 8;   // LED VERDE

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // FUNCIÓN SEMÁFORO
  
  // Apagar todos
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  
  // ROJO - 2 segundos
  digitalWrite(LED1, HIGH);
  delay(2000);
  digitalWrite(LED1, LOW);
  
  // AMARILLO - 1 segundo
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  
  // VERDE - 2 segundos
  digitalWrite(LED3, HIGH);
  delay(2000);
  digitalWrite(LED3, LOW);
  
  // Pausa antes de repetir
  delay(1000);
}
