#ifndef MOTION_LOGIC_H
#define MOTION_LOGIC_H

#include <Arduino.h>
#include "pir_sensor.h"
#include "hall_sensor.h"
#include "microwave_sensor.h"
#include "led.h"
#include "alarm.h"


void setupSensors();

void handleRadarMovementTask(void *parameter);
void handleHallMovementTask(void *paramter);
void handlePirMovementTask(void *parameter);
void possibleHumanMovementDetectedTask(void *parameter);


#endif