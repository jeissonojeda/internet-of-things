import serial
import time
from supabase import create_client, Client
from getPort import detectBoardPort

# Configura tu URL y KEY de Supabase
url = "https://gdxywvgzzuczwyhrwhjt.supabase.co"
key = "eeyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImdkeHl3dmd6enVjend5aHJ3aGp0Iiwicm9sZSI6ImFub24iLCJpYXQiOjE3NjE4NjAwMDcsImV4cCI6MjA3NzQzNjAwN30.sLckqDAMLwCgrFdZWTAZ-YDE5T7LT23_XMDg5NR_uE0"
supabase: Client = create_client(url, key)

arduino_port = detectBoardPort()
if not arduino_port:
    print("No Arduino detected. Exiting.")
    exit()

baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2)  # tiempo para estabilizar conexión

while True:
    data = ser.readline().decode('utf-8').rstrip()
    if data:
        print(f"Datos recibidos: {data}")
        try:
            humidity, temperature = data.split(",")
            humidity = float(humidity)
            temperature = float(temperature)

            # Envío a Supabase
            response = supabase.table("data").insert({
                "humidity": humidity,
                "temperature": temperature
            }).execute()

            if response.status_code == 201:
                print(f"✅ Datos enviados: Humedad={humidity}%, Temp={temperature}°C")
            else:
                print(f"❌ Error al enviar datos: {response.status_code}")

        except ValueError:
            print(f"⚠️ Formato de datos inválido: {data}")
        except Exception as e:
            print(f"❌ Error al enviar a Supabase: {e}")
    time.sleep(1)
