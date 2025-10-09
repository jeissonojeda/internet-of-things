#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
#define LED_RED 13
DHT dht(DHTPIN, DHTTYPE);
float humidity, temperature;

void setup() {
  pinMode(LED_RED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.println("Hello to weather station ::");
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  ");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C"); // Changed to println to add newline
  delay(2000);
}
