#include "setup_wifi.h"

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

void setup_wifi() {
  const char* ssid = WIFI_SSID;
  const char* password = WIFI_PASSWORD;
  
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  for (int i = 0; i < 1000 && WiFi.status() != WL_CONNECTED; ++i) {
      delay(500);
      Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Could not connect to wifi");
    delay(5000);
    ESP.restart();
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  printWifiStatus();
}