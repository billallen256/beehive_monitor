#include "serial.h"

void setup_serial()
{
  #ifdef START_SERIAL
    Serial.begin(9600);

    for (int i = 0; i < 1000 && !Serial; ++i) {
      delay(1);
    }
    
    if (!Serial) {
      ESP.restart();
    }

    Println("setup_serial() complete");
  #endif
}