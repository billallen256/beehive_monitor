#include "temperature.h"

// Create the AHT20 temperature sensor object
Adafruit_AHTX0 tempsensor = Adafruit_AHTX0();

void setup_temperature()
{
  /* Initialise the ADT7410 */
  if (!tempsensor.begin())
  {
    Println("Couldn't find AHT20!");
    delay(5000);
    ESP.restart();
  }
 
  // sensor takes 250 ms to get first readings
  delay(250);

  Println("setup_temperature() complete");
}

void populate_temperature_and_humidity() {
  sensors_event_t humidity_event;
  sensors_event_t temperature_event;
  tempsensor.getEvent(&humidity_event, &temperature_event);
  readings.humidity = humidity_event.relative_humidity;
  readings.temperature = temperature_event.temperature;
}