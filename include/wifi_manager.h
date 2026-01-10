#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include <Arduino.h> 

extern char* WIFI_SSID;
extern char* WIFI_PASSWORD;
void WiFiCheckTask(void* parameter);
void connectToWiFi( char* ssid,  char* password);


#endif // WIFI_MANAGER_H
