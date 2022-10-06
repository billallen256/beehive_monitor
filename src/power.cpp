#include "power.h"

void populate_voltage() {
    readings.voltage = 2 * analogRead(POWER_PIN);
}