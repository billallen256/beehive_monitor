#ifndef _SETUP_WIFI_H_
#define _SETUP_WIFI_H_ 1

#include <WiFi.h>

#include "readings.h"
#include "sleep.h"
#include "ssid.h"
#include "statsd.h"

void setup_wifi(unsigned int);

#endif