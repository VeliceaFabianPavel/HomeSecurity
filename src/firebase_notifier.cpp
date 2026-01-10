#include "firebase_notifier.h"

FirebaseNotifier::FirebaseNotifier(const String& functionUrl)
    : url(functionUrl) {}

bool FirebaseNotifier::sendNotification(const String& title, const String& body, const String& token) {
    WiFiClientSecure client;
    client.setInsecure(); // ⚠️ folosește cu grijă în producție

    HTTPClient https;
    if (!https.begin(client, url)) {
        Serial.println("[FirebaseNotifier] Eroare la initializarea HTTP");
        return false;
    }

    https.addHeader("Content-Type", "application/json");

    String jsonPayload = "{\"title\":\"" + title + "\",\"body\":\"" + body + "\",\"token\":\"" + token + "\"}";

    int httpCode = https.POST(jsonPayload);

    if (httpCode > 0) {
        String response = https.getString();
        Serial.printf("[FirebaseNotifier] Raspuns (%d): %s\n", httpCode, response.c_str());
        https.end();
        return (httpCode == 200);
    } else {
        Serial.printf("[FirebaseNotifier] Eroare POST: %s\n", https.errorToString(httpCode).c_str());
        https.end();
        return false;
    }
}
