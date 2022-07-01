// based on https://www.alejandrowurts.com/projects/esp32-wifi-udp/

#include <WiFi.h>
#include <WiFiUdp.h>

#include "gauge.h"
#include "serial.h"
#include "sleep.h"
#include "ssid.h"
#include "temperature.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const unsigned int statsdPort = 8125;
int status = WL_IDLE_STATUS;

IPAddress server(192, 168, 1, 121);  // using IP instead of DNS

WiFiUDP udpClient;

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

char humidity_buffer[GAUGE_BUFFER_SIZE];
char temperature_buffer[GAUGE_BUFFER_SIZE];

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
  
  deep_sleep(10*60);
}

void setup() {
  setup_serial();

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  printWifiStatus();

  setup_temperature();
  send_temperature_and_humidity();
}

// Note: We are using ESP32's deep sleep
// which calls setup each time we wake up
// so there's no need to use loop. Every
// wakeup is a new day.
void loop() {
  
}