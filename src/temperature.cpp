#include "temperature.h"

// Create the AHT20 temperature sensor object
Adafruit_AHTX0 tempsensor = Adafruit_AHTX0();

void setup_temperature()
{
  /* Initialise the ADT7410 */
  if (!tempsensor.begin())
  {
    Println("Couldn't find AHT20!");
    while (1)
      ;
  }
 
  // sensor takes 250 ms to get first readings
  delay(250);

  Println("setup_temperature() complete");
}