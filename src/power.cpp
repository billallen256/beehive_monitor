#include "power.h"

uint16_t get_voltage() {
    return 2 * analogRead(POWER_PIN);
}