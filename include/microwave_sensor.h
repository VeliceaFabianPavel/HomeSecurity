#ifndef MICROWAVE_SENSOR_H
#define MICROWAVE_SENSOR_H

#include <Arduino.h>

#define MICROWAVE_SENSOR 22 // Pinul la care este conectat senzorul radar

void setupMicrowaveSensor();
bool isRadarActive();

#endif