#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADT7410.h>

#include "gauge.h"
#include "serial.h"

#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_ 1

extern Adafruit_ADT7410 tempsensor;

void setup_temperature();

#endif