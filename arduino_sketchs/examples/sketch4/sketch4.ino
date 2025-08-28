int const LED1 = 13;  // LED izquierdo
int const LED2 = 12;  // LED centro
int const LED3 = 8;   // LED derecho

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Parpadeo rápido 3 veces (strober)
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(50);  // Encendido rápido
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(50);  // Apagado rápido
  }
  
  // Apagar todos los LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);  // Pausa antes del encendido secuencial
  
  // Encender LEDs de izquierda a derecha (hacia la derecha)
  digitalWrite(LED1, HIGH);  // Enciende LED1 (izquierdo)
  delay(300);
  
  digitalWrite(LED2, HIGH);  // Enciende LED2 (centro)
  delay(300);
  
  digitalWrite(LED3, HIGH);  // Enciende LED3 (derecho)
  delay(1000);  // Mantiene todos encendidos por 1 segundo
  
  // Apagar todos para repetir el ciclo
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);  // Pausa antes de repetir
}
