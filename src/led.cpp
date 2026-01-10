#include "led.h"

void setupLed() {
  pinMode(yellowLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);    
}

/**
 * Aprinde LED-ul galben.
 */
void turnYellowLedOn() {
  digitalWrite(yellowLED, HIGH);
}

/**
 * Stinge LED-ul galben.
 */
void turnYellowLedOff() {
  digitalWrite(yellowLED, LOW);
}

/**
 * Aprinde LED-ul albastru.
 */
void turnBlueLedOn() {
  digitalWrite(blueLED, HIGH);
}

/**
 * Stinge LED-ul albastru.
 */
void turnBlueLedOff() {
  digitalWrite(blueLED, LOW);
}

/**
 * Aprinde LED-ul roșu.
 */
void turnRedLedOn() {
  digitalWrite(redLED, HIGH);
}

/**
 * Stinge LED-ul roșu.
 */
void turnRedLedOff() {
  digitalWrite(redLED, LOW);
}

/**
 * Aprinde LED-ul verde.
 */
void turnGreenLedOn() {
  digitalWrite(greenLED, HIGH);
}

/**
 * Stinge LED-ul verde.
 */
void turnGreenLedOff() {
  digitalWrite(greenLED, LOW);
}
/**
 * Aprinde LED-ul alb.
 */
void turnWhiteLedOn() {
  digitalWrite(whiteLED, HIGH);
}
/**
 * Stinge LED-ul alb.
 */
void turnWhiteLedOff() {
  digitalWrite(whiteLED, LOW);
}
