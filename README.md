# 🌡️ Proyecto Arduino: Sensor TMP36 con LCD, LED y Motor

## 📚 Descripción general
Este proyecto forma parte de la **Guía de Laboratorio 4** de la asignatura **Sistemas Operativos** en la Universidad CESMAG.  
El objetivo es **programar rutinas en Arduino** que permitan leer la temperatura ambiente usando el sensor **TMP36**, visualizarla en una **pantalla LCD 16x2** y controlar el comportamiento de un **LED** y un **motor (ventilador)** de acuerdo con la temperatura medida.

---

## ⚙️ Componentes utilizados
| Componente | Función |
|-------------|----------|
| Arduino UNO | Microcontrolador principal |
| Sensor TMP36 | Sensor analógico de temperatura |
| Pantalla LCD 16x2 | Visualización del valor de la temperatura |
| LED | Indicador visual de temperatura baja o alta |
| Motor DC | Simula un ventilador que se activa con altas temperaturas |
| Transistor NPN (2N2222 o TIP120) | Control de potencia del motor |
| Diodo 1N4007 | Protección del transistor ante picos de corriente |
| Resistencias 220Ω, 1kΩ | Limitación de corriente para LED y transistor |
| Potenciómetro 10kΩ | Control del contraste del LCD |
| Protoboard y cables | Conexiones del circuito |

---

## 🔌 Conexiones principales
- **TMP36:** Señal → A0  
- **LED:** Ánodo → pin 8 (con resistencia 220Ω)  
- **Motor:** Controlado por pin 9 a través de transistor NPN  
- **LCD:** RS → 12, E → 11, D4 → 5, D5 → 4, D6 → 3, D7 → 2  
- **Alimentación:** +5V y GND comunes  

---

## 💻 Código principal (`temp_lcd.ino`)
El código realiza las siguientes tareas:

1. Lee la temperatura del sensor **TMP36**.
2. Muestra el valor de la temperatura en el **LCD 16x2** usando la instrucción `lcd_1.print()`.
3. Controla el **LED** y el **motor** según la temperatura:

| Rango de temperatura | LED | Motor | Acción |
|----------------------|-----|--------|--------|
| ≤ 10 °C | Parpadea cada 0.5 s | Apagado | Temperatura baja |
| 11 °C – 25 °C | Apagado | Apagado | Temperatura normal |
| ≥ 26 °C | Encendido fijo | Encendido | Temperatura alta |

---

## 🧠 Lógica de funcionamiento
El programa usa la fórmula:
