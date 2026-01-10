#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include "led.h"

#define PIR_SENSOR 21

void setupPirSensor();
void calibratePirSensorTask(void* parameter);
bool isPirActive();

extern bool pirCalibrated;
extern unsigned long pirCalibrationStart;
 
#endif