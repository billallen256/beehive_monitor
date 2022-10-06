#include "readings.h"

Readings readings;

void print_readings() {
    Serial.printf(
        "hum: %f, temp: %f, volt: %d\n",
        readings.humidity,
        readings.temperature,
        readings.voltage
    );
}