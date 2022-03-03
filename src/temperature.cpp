#include "temperature.h"

// Create the ADT7410 temperature sensor object
Adafruit_ADT7410 tempsensor = Adafruit_ADT7410();

void setup_temperature()
{
  /* Initialise the ADT7410 */
  if (!tempsensor.begin())
  {
    Println("Couldn't find ADT7410!");
    while (1)
      ;
  }
 
  // sensor takes 250 ms to get first readings
  delay(250);

  Println("setup_temperature() complete");
}