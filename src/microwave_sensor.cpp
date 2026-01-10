#include "microwave_sensor.h"


void setupMicrowaveSensor() {
    pinMode(MICROWAVE_SENSOR, INPUT);
}

bool isRadarActive() {
    bool retVal = false;
    bool radarRead = digitalRead(MICROWAVE_SENSOR);

    if (radarRead == HIGH) {
        retVal = true;
       Serial.println("[ALERT] Radarul detectează mișcare!");
        
    }
    return retVal;
}