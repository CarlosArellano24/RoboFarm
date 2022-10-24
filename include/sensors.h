#pragma once
#include <Adafruit_Sensor.h>
#include <DHT.H>

namespace sensors {
  const uint8_t dhtPin = 2;
  DHT dht(dhtPin, DHT11);
}