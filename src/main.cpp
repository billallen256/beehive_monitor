// based on https://www.alejandrowurts.com/projects/esp32-wifi-udp/

#include <WiFiUdp.h>

#include "power.h"
#include "serial.h"
#include "temperature.h"
#include "setup_wifi.h"

const unsigned int sleep_seconds = 10 * 60;
//const unsigned int sleep_seconds = 20;

void setup() {
  setup_serial();

  // Get the voltage before wifi is enabled
  // because they both use GPIO pin 13.
  populate_voltage();

  setup_temperature();
  populate_temperature_and_humidity();
  print_readings();

  setup_wifi(sleep_seconds);
}

// Note: We are using ESP32's deep sleep
// which calls setup() each time we wake up
// so there's no need to use loop.
void loop() {
  
}