#ifndef _SLEEP_H_
#define _SLEEP_H_ 1

#include <Arduino.h>
#include "esp_sleep.h"

#define uS_TO_S_FACTOR 1000000

extern RTC_DATA_ATTR unsigned int boot_count;

void deep_sleep(unsigned int);
void reboot_after_boot_count(unsigned int);
void increment_boot_count();
unsigned int get_boot_count();

#endif