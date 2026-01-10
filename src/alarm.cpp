// alarm.cpp
#include "alarm.h"

bool isAlarmActive  = false;
static unsigned long alarmStartTime = 0;

void setupAlarm() {
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(BUZZER_PIN, OUTPUT);
  
}


/**
 * @brief Pornește alarma dacă nu este deja activă. (Non-blocant)
 */
void triggerAlarm() {
  if (!isAlarmActive) {
    isAlarmActive = true;
    alarmStartTime = millis();
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("[ALARM] Alarma a fost pornită.");
  }
}

/**
 * @brief Gestionează starea alarmei, oprind-o după expirarea duratei.
 * Această funcție este non-blocantă și trebuie apelată repetat.
 */
void handleAlarm() {
  if (isAlarmActive && (millis() - alarmStartTime >= ALARM_DURATION)) {
    digitalWrite(BUZZER_PIN, LOW);
    isAlarmActive = false;
    Serial.println("[ALARM] Alarma a fost oprită.");
  }
}



// void triggerAlarm() {
//   if (!alarmTriggered) {
//     alarmTriggered = true;
//     Serial.println("ALARMĂ: Porneste alarma!");
//     digitalWrite(BUZZER_PIN, HIGH);
//     // delay(ALARM_DURATION);
//     vTaskDelay(pdMS_TO_TICKS(ALARM_DURATION));
//     digitalWrite(BUZZER_PIN, LOW);
//   }
// }

// void triggerAlarm() {
//     if (alarmTriggered) {
//         // Verificăm dacă a trecut timpul
//         if (millis() - alarmStartTime >= ALARM_DURATION) {
//             digitalWrite(BUZZER_PIN, LOW);
//             alarmTriggered = false;
//             Serial.println("[ALARM] Buzzer oprit (timeout).");
//         }
//         return;
//     }

//     // Dacă nu e activ, îl pornim
//     alarmTriggered = true;
//     alarmStartTime = millis();
//     digitalWrite(BUZZER_PIN, HIGH);
//     Serial.println("[ALARM] Buzzer pornit.");
// }

