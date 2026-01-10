#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

#define yellowLED 19
#define blueLED 18
#define redLED 23
#define greenLED 4
#define whiteLED 13

void setupLed();
void turnYellowLedOn();
void turnBlueLedOn();
void turnRedLedOn();
void turnYellowLedOff();
void turnBlueLedOff();
void turnRedLedOff();
void turnGreenLedOn();
void turnGreenLedOff();
void turnWhiteLedOn();
void turnWhiteLedOff();
void turnAllLedsOff();
void turnAllLedsOn();

#endif // LEDS_H