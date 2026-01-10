#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include <Arduino.h>
#define HALL_SENSOR 33 // Pinul la care este conectat senzorul de ușă

void setupHallSensor();
bool isHallSensorTriggered();

#endif
