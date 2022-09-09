#include "sleep.h"

RTC_DATA_ATTR unsigned int boot_count = 0;

void deep_sleep(unsigned int seconds) {
  esp_sleep_enable_timer_wakeup(seconds * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void reboot_after_boot_count(unsigned int boot_limit) {
  if (boot_count > boot_limit) {
    ESP.restart();
  }
}

void increment_boot_count() {
  ++boot_count;
}

unsigned int get_boot_count() {
  return boot_count;
}