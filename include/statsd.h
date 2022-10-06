#ifndef _STATSD_H_
#define _STATSD_H_

#include <WiFiUdp.h>

#include "gauge.h"
#include "readings.h"

void send_readings();

#endif