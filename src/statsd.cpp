#include "statsd.h"

const unsigned int statsdPort = 8125;

IPAddress server(192, 168, 1, 116);  // using IP instead of DNS

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

void send_readings() {
  Gauge_str(humidity_buffer, "garage.humid", (int)(readings.humidity*100));
  Gauge_str(temperature_buffer, "garage.temp", (int)(readings.temperature*100));
  Gauge_str(voltage_buffer, "garage.voltage", (int)readings.voltage);

  send(humidity_buffer);
  send(temperature_buffer);
  send(voltage_buffer);
}