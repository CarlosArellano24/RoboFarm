#include <Arduino.h>
#include "modules.h"
#include "sensors.h"

#define led 13

void printSensorValues(float&, float&);

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  sensors::dht.begin();
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
}