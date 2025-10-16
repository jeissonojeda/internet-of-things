
# 🌐 Proyecto: Internet of Things (IoT) – Control de Temperatura con Arduino

Este proyecto implementa un sistema básico de **IoT** utilizando **Arduino UNO**, un **sensor de temperatura TMP36**, un **motor (ventilador)**, un **LED indicador** y una **pantalla LCD 16x2**.  
El sistema permite visualizar la temperatura en tiempo real y activar dispositivos de salida según el valor medido.

---

## 🧠 Objetivo
Desarrollar un sistema embebido que lea la temperatura ambiente mediante el sensor TMP36 y realice acciones automáticas de control (encendido de ventilador y LED) con base en tres rangos de temperatura definidos.

---

## 🧰 Componentes utilizados
- Arduino UNO  
- Sensor de temperatura TMP36  
- Pantalla LCD 16x2 (modo paralelo)  
- Potenciómetro 10kΩ (para contraste LCD)  
- Motor DC + transistor NPN + diodo 1N4007 + resistencia de 1kΩ  
- LED + resistencia de 220Ω  
- Protoboard y cables de conexión

---

## ⚡ Lógica de funcionamiento

| Rango de temperatura         | Acción del LED         | Acción del motor          |
|------------------------------|-------------------------|----------------------------|
| ≤ 10 °C                      | Parpadea cada 0.5 s     | Apagado                   |
| 11 °C – 25 °C                | Apagado                | Apagado                   |
| ≥ 26 °C                      | Encendido fijo         | Encendido                 |

---

## 🧾 Código fuente principal

Archivo: `temp_lcd.ino`

Características:
- Lectura de temperatura desde TMP36.  
- Visualización en pantalla LCD con `lcd_1.print()`.  
- Control de LED y motor mediante sentencias `if` y `digitalWrite()`.  
- Salida de datos por monitor serial.

---

## 🔌 Conexiones principales

- TMP36 → A0 (señal), 5 V (VCC), GND  
- LED → Pin 7 con resistencia 220Ω  
- Motor → Pin 8 (controlado con transistor + diodo)  
- LCD → RS (12), E (11), D4 (5), D5 (4), D6 (3), D7 (2)  
- Potenciómetro → VO de LCD para contraste

---

## 🧪 Validaciones
1. Temperatura baja: LED parpadea, ventilador apagado.  
2. Temperatura normal: LED y motor apagados.  
3. Temperatura alta: LED encendido fijo, motor encendido.

---


