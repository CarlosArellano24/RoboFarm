#include <Arduino.h>
#include "modules.h"
#include "sensors.h"
#include "hmi.h"

#define led 13

void printSensorValues(float&, float&);

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);



  sensors::dht.begin();
  hmi::lcd.begin(16, 2);
}

void loop() {
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);

  float temperature = sensors::dht.readTemperature();
  float airHumidity = sensors::dht.readHumidity();

  printSensorValues(temperature, airHumidity);
}

void printSensorValues(float& temperature, float& airHumidity) {
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("° C    Air Humidity: ");
  Serial.print(airHumidity);
  Serial.println("%");

  hmi::lcd.clear();
  hmi::lcd.setCursor(0, 0);
  hmi::lcd.write("temperatura: ");
  hmi::lcd.write(temperature);
  hmi::lcd.setCursor(0, 1);
}