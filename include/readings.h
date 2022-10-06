#ifndef _READINGS_H_
#define _READINGS_H_

#include <Arduino.h>

struct Readings {
    float humidity;
    float temperature;
    uint16_t voltage;
};

void print_readings();

extern Readings readings;

#endif