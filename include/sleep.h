#ifndef _SLEEP_H_
#define _SLEEP_H_ 1

#include <Arduino.h>
#include "esp_sleep.h"

#define uS_TO_S_FACTOR 1000000

void deep_sleep(unsigned int);

#endif