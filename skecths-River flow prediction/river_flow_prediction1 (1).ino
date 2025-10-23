
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  // Inicializar comunicación serial
  Serial.begin(9600);
  Serial.println("=== SISTEMA DE DETECCIÓN DE NIVEL DE AGUA ===");
  Serial.println("=== River Flow Prediction System ===");
  Serial.println("Iniciando monitoreo...\n");
  
  // Configurar pines de los LEDs como salidas
  pinMode(4, OUTPUT);   // LED VERDE - Nivel normal
  pinMode(8, OUTPUT);   // LED AMARILLO - Alerta media
  pinMode(13, OUTPUT);  // LED ROJO - Alerta alta
}

void loop()
{
  // Leer distancia del sensor una sola vez
  float distancia = 0.01723 * readUltrasonicDistance(2, 3);
  
  // Mostrar distancia en monitor serial
  Serial.print("Distancia al agua: ");
  Serial.print(distancia);
  Serial.print(" cm - ");
  
  // LED ROJO: Distancia 0-100 cm (Alerta alta - Nivel peligroso)
  if (distancia > 0 && distancia <= 100) {
    digitalWrite(4, LOW);    // LED VERDE apagado
    digitalWrite(8, LOW);    // LED AMARILLO apagado
    digitalWrite(13, HIGH);  // LED ROJO encendido
    Serial.println("¡ALERTA ROJA! Nivel peligroso - Riesgo de desbordamiento");
  } 
  // LED AMARILLO: Distancia 101-200 cm (Alerta media - Nivel en aumento)
  else if (distancia > 100 && distancia <= 200) {
    digitalWrite(4, LOW);    // LED VERDE apagado
    digitalWrite(8, HIGH);   // LED AMARILLO encendido
    digitalWrite(13, LOW);   // LED ROJO apagado
    Serial.println("ALERTA AMARILLA - Nivel en aumento - Monitoreo constante");
  }
  // LED VERDE: Distancia > 200 cm (Nivel normal - Agua lejos)
  else if (distancia > 200) {
    digitalWrite(4, HIGH);   // LED VERDE encendido
    digitalWrite(8, LOW);    // LED AMARILLO apagado
    digitalWrite(13, LOW);   // LED ROJO apagado
    Serial.println("NIVEL NORMAL - Sin riesgo - Condiciones seguras");
  }
  // Sin lectura válida o fuera de rango
  else {
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(13, LOW);
  }
  
  Serial.println("------------------------------------");
  
  delay(1000); // Esperar 1 segundo entre lecturas
}