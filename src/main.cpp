// based on https://www.alejandrowurts.com/projects/esp32-wifi-udp/

#include <WiFiUdp.h>

#include "gauge.h"
#include "power.h"
#include "serial.h"
#include "sleep.h"
#include "temperature.h"
#include "setup_wifi.h"

const unsigned int sleep_seconds = 10 * 60;
const unsigned int statsdPort = 8125;
int status = WL_IDLE_STATUS;

IPAddress server(192, 168, 1, 117);  // using IP instead of DNS

WiFiUDP udpClient;

char humidity_buffer[GAUGE_BUFFER_SIZE];
char temperature_buffer[GAUGE_BUFFER_SIZE];
char voltage_buffer[GAUGE_BUFFER_SIZE];
char boot_count_buffer[GAUGE_BUFFER_SIZE];

void send(char *msg) {
  Serial.printf("Sending: %s\n", msg);
  udpClient.beginPacket(server, statsdPort);
  udpClient.printf(msg);
  udpClient.endPacket();
}

void send_temperature_and_humidity() {
  sensors_event_t humidity_event;
  sensors_event_t temperature_event;
  tempsensor.getEvent(&humidity_event, &temperature_event);
  
  Gauge_str(humidity_buffer, "hive.humid", (int)(humidity_event.relative_humidity*100));
  Gauge_str(temperature_buffer, "hive.temp", (int)(temperature_event.temperature*100));
  
  send(humidity_buffer);
  send(temperature_buffer);
}

void send_voltage(uint16_t voltage) {
  Gauge_str(voltage_buffer, "hive.voltage", (int)voltage);
  send(voltage_buffer);
}

void send_boot_count() {
  Gauge_str(boot_count_buffer, "hive.boots", (int)get_boot_count());
  send(boot_count_buffer);
}

void setup() {
  reboot_after_boot_count(144);
  increment_boot_count();

  // Get the voltage before wifi is enabled
  // because they both use GPIO pin 13.
  uint16_t voltage = get_voltage();

  setup_serial();
  setup_wifi();
  setup_temperature();
  send_temperature_and_humidity();
  send_voltage(voltage);
  send_boot_count();
  deep_sleep(sleep_seconds);
}

// Note: We are using ESP32's deep sleep
// which calls setup() each time we wake up
// so there's no need to use loop.
void loop() {
  
}