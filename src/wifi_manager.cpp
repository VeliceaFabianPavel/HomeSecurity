#include "wifi_manager.h"
#include "led.h"
// Definirea unui timp maxim de așteptare în milisecunde
const unsigned long WIFI_CONNECTION_TIMEOUT = 15000; // 15 secunde
char* WIFI_SSID = "IonutMoto";
char* WIFI_PASSWORD = "12345678";

void connectToWiFi( char* ssid,  char* password) {
    Serial.print("Conectare la reteaua: ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    unsigned long startTime = millis();

    // Așteaptă conectarea sau expirarea timpului
    while (WiFi.status() != WL_CONNECTED) {
        if (millis() - startTime > WIFI_CONNECTION_TIMEOUT) {
            Serial.println("\nConectare esuata (timeout)!");
            return; // Ieși din funcție dacă a durat prea mult
        }
        Serial.print(".");
       
        
    }

    // Aici ajunge doar dacă s-a conectat cu succes
    Serial.println("\nConectat la reteaua WiFi!");
    turnWhiteLedOn();
   
}

void WiFiCheckTask(void* parameter) {
     
    for (;;) {
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("Conexiune WiFi pierduta. Se incearca reconectarea...");
            connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
        }

        vTaskDelay(pdMS_TO_TICKS(500)); // verifică la fiecare 10 secunde
    }
}
