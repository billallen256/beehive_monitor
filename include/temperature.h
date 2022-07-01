#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_AHTX0.h>

#include "gauge.h"
#include "serial.h"

#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_ 1

extern Adafruit_AHTX0 tempsensor;

void setup_temperature();

#endif