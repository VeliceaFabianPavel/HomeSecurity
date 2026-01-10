// alarm.h
#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>
#define BUZZER_PIN 25
#define ALARM_DURATION 3000  

void setupAlarm();
void triggerAlarm();
void handleAlarm();

#endif
