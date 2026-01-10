#include "motion_logic.h"
#include "firebase_notifier.h"

FirebaseNotifier notifier("https://trimitenotificare-k4cqa7es6q-uc.a.run.app");

// const char* fcmToken = "eRiTsUcEQie-m46eBIpPUk:APA91bE8Kjw3gJ2BWzmmsZqNaSEZGetyKLiecFPD9TlHadBXWdV4KZgAjk9z-epH68vFKLZoGHJG0feMF3BxaOJPBnWwhuNz4AObnWxwQWWzTbFF2EcgsV4";
const char* fcmToken = "d-OlFNUNSaSStUUsL05ofB:APA91bEd8ifGV-IIX15CJZHAbQovskC4MzL32mM5iDDON5GwLeoFdeWnYgYar0-lrmNf4lxb0AK54yycQB8TD_DMpMU4LOOp-UwBM_8Bi4DTAi1pYVpuNbA";

void setupSensors() {
    setupPirSensor();
    setupHallSensor();
    setupMicrowaveSensor();
    setupLed();
    setupAlarm();
}



void handleHallMovementTask(void *paramter){
    for(;;){
        if(pirCalibrated){
        bool hall = isHallSensorTriggered();

        if (hall) {
            turnYellowLedOn();  
        } else {
            turnYellowLedOff(); 
        }
    }
vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void handlePirMovementTask(void *parameter){
    for (;;) {
        if(pirCalibrated){
            bool pir = isPirActive();

            if (pir) {
                Serial.println("[ALERT] Mișcare detectată la PIR!");
                turnBlueLedOn();  // Aprinde LED-ul albastru pentru a indica mișcarea
            } else {
                turnBlueLedOff(); // Stinge LED-ul albastru dacă nu este detectată mișcare
            }
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
void possibleHumanMovementDetectedTask(void *parameter) {
    static bool notificareTrimisa = false;

    for (;;) {

         handleAlarm();

        bool pirActive = isPirActive();
        bool hallActive = isHallSensorTriggered();



        if (pirActive || hallActive) {
            if (!notificareTrimisa) {
                Serial.println("[ALERT] Posibilă mișcare umană detectată!");

                triggerAlarm();
                
                // Trimite notificare
                notifier.sendNotification(
                   "Mișcare detectată",
                   "Sistemul a detectat o posibilă mișcare umană.",
                   fcmToken
               );

                notificareTrimisa = true; // Marchează că am trimis
            }
        } else {
            notificareTrimisa = false; // Resetăm flagul dacă nu mai e mișcare
        }
           


        vTaskDelay(pdMS_TO_TICKS(50));
    }
}


// void possibleHumanMovementDetectedTask(void *parameter){
//     // Verificăm dacă senzorul PIR este activ
//     bool pirActive = isPirActive();
//     // Verificăm dacă senzorul radar este activ
//     bool hallActive = isHallSensorTriggered();
//     for(;;){

//     if (pirActive || hallActive) {
//         Serial.println("[ALERT] Posibilă mișcare umană detectată!");
//         triggerAlarm();  // Poate declanșa o alarmă sau trimite o notificare
        
//     } else {
       
//     }
//          vTaskDelay(pdMS_TO_TICKS(100));
//     }
// }


void handleRadarMovementTask(void *parameter) {
    static unsigned long radarStartTime = 0;
    static bool notificareTrimisa = false;

    for (;;) {
        if (isRadarActive()) {
            if (radarStartTime == 0) {
                radarStartTime = millis(); // Începem cronometrul
            }

            if (millis() - radarStartTime >= 2000) {
                Serial.println("[ALERT] Mișcare umană confirmată de radar!");
                turnRedLedOn();

                if (!notificareTrimisa) {
                    notifier.sendNotification(
                        "Mișcare confirmată",
                        "Radarul a detectat o mișcare continuă.",
                        fcmToken
                    );
                    notificareTrimisa = true; // Trimitem o singură dată
                }
            }
        } else {
            radarStartTime = 0;       // Resetăm cronometrul
            notificareTrimisa = false; // Permitem o nouă notificare la următoarea activare
            turnRedLedOff();
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}



// void handleRadarMovementTask(void *parameter) {
//     // Variabilă statică pentru a memora momentul când a început detecția.
//     // '0' înseamnă că niciun cronometru nu este activ.
//     static unsigned long radarStartTime = 0;
//     for(;;){
//     // Verificăm dacă senzorul radar este activ
//     if (isRadarActive()) {
//         // Radar-ul este activ.

//         // Dacă este prima dată când îl vedem activ (cronometrul e 0), pornim cronometrul.
//         if (radarStartTime == 0) {
//             radarStartTime = millis();
//         }

//         // Verificăm dacă au trecut 2 secunde (2000 ms) de activitate continuă.
//         if (millis() - radarStartTime >= 1000) {
//             // CONDIȚIE ÎNDEPLINITĂ: Mișcare confirmată.
//             // Executăm acțiunile direct aici.
//             Serial.println("[ALERT] Mișcare umană confirmată de radar!");
//             turnRedLedOn(); // Sau orice altă acțiune dorită
//         }

//     } else {
//         // Radar-ul NU este activ. Resetăm totul.
//         radarStartTime = 0; // Oprim cronometrul
//         turnRedLedOff();   // Oprim acțiunea (ex: stingem LED-ul)
//     }   //inlocuiesc cu if(retval/status) { ... } pentru a evita confuziile
// vTaskDelay(pdMS_TO_TICKS(100));
// }
// }
