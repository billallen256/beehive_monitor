#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_ 1

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_AHTX0.h>

#include "readings.h"
#include "serial.h"

extern Adafruit_AHTX0 tempsensor;

void setup_temperature();
void populate_temperature_and_humidity();

#endif