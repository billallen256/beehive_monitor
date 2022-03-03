#include "sleep.h"

void deep_sleep(unsigned int seconds) {
  esp_sleep_enable_timer_wakeup(seconds * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}