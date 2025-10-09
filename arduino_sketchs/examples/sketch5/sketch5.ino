char opt;
const int BUTTON_PIN = 7;
const int LED_RED = 13;
const int LED_YELLOW = 12;
const int LED_GREEN = 8;
int step = 0; 
void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 

  Serial.begin(9600);
  Serial.println("Bienvenido");
  Serial.println("**** MENU PRINCIPAL ****");
  menu();
}

void loop() {
 
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50);
    if (digitalRead(BUTTON_PIN) == LOW) { 
      step = (step % 9) + 1; 
      handleStep(step);
      while (digitalRead(BUTTON_PIN) == LOW); 
    }
  }

  // Mantén la funcionalidad original por serial
  if (Serial.available() > 0) {
    opt = Serial.read();

    if (opt == '1') {
      digitalWrite(LED_RED, HIGH);
      Serial.println("LED ROJO ENCENDIDO");
    } 
    else if (opt == '2') {
      digitalWrite(LED_RED, LOW);
      Serial.println("LED ROJO APAGADO");
    } 
    else if (opt == '3') {
      digitalWrite(LED_YELLOW, HIGH);
      Serial.println("LED AMARILLO ENCENDIDO");
    } 
    else if (opt == '4') {
      digitalWrite(LED_YELLOW, LOW);
      Serial.println("LED AMARILLO APAGADO");
    } 
    else if (opt == '5') {
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("LED VERDE ENCENDIDO");
    } 
    else if (opt == '6') {
      digitalWrite(LED_GREEN, LOW);
      Serial.println("LED VERDE APAGADO");
    } 
    else if (opt == '7') {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("TODOS LOS LEDs ENCENDIDOS");
    } 
    else if (opt == '8') {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      Serial.println("TODOS LOS LEDs APAGADOS");
    } 
    else if (opt == '9') {
      Serial.println("INTERMITENCIA DE LEDs...");
      for (int i = 0; i < 10; i++) {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);
        delay(500);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(500);
      }
      Serial.println("INTERMITENCIA FINALIZADA.");
    } 
    else {
      Serial.println("Opción no válida. Intenta de nuevo.");
    }

   
    menu();
  }
}

void handleStep(int step) {
  switch (step) {
    case 1:
      digitalWrite(LED_RED, HIGH);
      Serial.println("LED ROJO ENCENDIDO");
      break;
    case 2:
      digitalWrite(LED_RED, LOW);
      Serial.println("LED ROJO APAGADO");
      break;
    case 3:
      digitalWrite(LED_YELLOW, HIGH);
      Serial.println("LED AMARILLO ENCENDIDO");
      break;
    case 4:
      digitalWrite(LED_YELLOW, LOW);
      Serial.println("LED AMARILLO APAGADO");
      break;
    case 5:
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("LED VERDE ENCENDIDO");
      break;
    case 6:
      digitalWrite(LED_GREEN, LOW);
      Serial.println("LED VERDE APAGADO");
      break;
    case 7:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("TODOS LOS LEDs ENCENDIDOS");
      break;
    case 8:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      Serial.println("TODOS LOS LEDs APAGADOS");
      break;
    case 9:
      Serial.println("INTERMITENCIA DE LEDs...");
      for (int i = 0; i < 10; i++) {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);
        delay(500);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(500);
      }
      Serial.println("INTERMITENCIA FINALIZADA.");
      break;
  }
  menu(); 
}

void menu() {
  Serial.println("\n[1] Encender LED ROJO");
  Serial.println("[2] Apagar LED ROJO");
  Serial.println("[3] Encender LED AMARILLO");
  Serial.println("[4] Apagar LED AMARILLO");
  Serial.println("[5] Encender LED VERDE");
  Serial.println("[6] Apagar LED VERDE");
  Serial.println("[7] Encender TODOS LOS LEDs");
  Serial.println("[8] Apagar TODOS LOS LEDs");
  Serial.println("[9] Intermitencia de TODOS LOS LEDs");
}
