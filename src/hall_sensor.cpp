#include "hall_sensor.h"

void setupHallSensor() {
  pinMode(HALL_SENSOR, INPUT_PULLUP);
}

bool isHallSensorTriggered() {
  bool retVal = false;
  bool hallSensor = digitalRead(HALL_SENSOR);

  if (hallSensor == HIGH) {
    retVal = true;
  } else {
    retVal = false;
  }

  return retVal;

}
