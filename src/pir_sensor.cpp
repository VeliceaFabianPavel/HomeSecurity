#include "pir_sensor.h"

bool pirCalibrated = false;
unsigned long pirCalibrationStart = 0;

void setupPirSensor() {
    pinMode(PIR_SENSOR, INPUT);
    pirCalibrationStart = millis();
}


void calibratePirSensorTask(void *parameter) {
    for(;;){
        if (!pirCalibrated && (millis() - pirCalibrationStart >= 30000)) {
            pirCalibrated = true;
            turnGreenLedOn(); 
        }
        else {
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

bool isPirActive() {
    bool retVal = false;
    if (!pirCalibrated) {
        return retVal;
    }

    bool pirRead = digitalRead(PIR_SENSOR);
    if (pirRead == HIGH) {
        retVal = true;
    }
    return retVal;
}