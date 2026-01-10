#ifndef FIREBASE_NOTIFIER_H
#define FIREBASE_NOTIFIER_H

#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

class FirebaseNotifier {
public:
    FirebaseNotifier(const String& functionUrl);
    bool sendNotification(const String& title, const String& body, const String& token);

private:
    String url;
};

#endif
