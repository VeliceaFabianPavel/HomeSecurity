#include "wifi_manager.h"
#include "motion_logic.h"

void setup() {
  Serial.begin(115200);
  setupSensors();
  connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("[SYSTEM] Initializare completă. Aștept calibrare...");

  xTaskCreate(WiFiCheckTask, "WiFiCheck", 2048, NULL, 2, NULL);               
  xTaskCreate(calibratePirSensorTask, "PIRCalibrate", 1536, NULL, 3, NULL);
  xTaskCreate(handleHallMovementTask, "HallSensor", 2048, NULL, 4, NULL);
  xTaskCreate(handlePirMovementTask, "PIRSensor", 2048, NULL, 4, NULL);
  xTaskCreate(handleRadarMovementTask, "RadarSensor", 6144, NULL, 3, NULL);
  xTaskCreate(possibleHumanMovementDetectedTask, "HumanMovement", 6144, NULL, 4, NULL);
}

// Bucla principală – verificare logică senzori și semnalare
void loop() {
  vTaskDelay(1000);

  
  
}
