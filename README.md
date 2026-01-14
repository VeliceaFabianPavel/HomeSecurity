<p align="center">
  <img src="https://img.shields.io/badge/ESP32-Embedded-blue?style=for-the-badge&logo=espressif&logoColor=white" alt="ESP32"/>
  <img src="https://img.shields.io/badge/FreeRTOS-Real--Time%20OS-green?style=for-the-badge" alt="FreeRTOS"/>
  <img src="https://img.shields.io/badge/Firebase-Cloud-orange?style=for-the-badge&logo=firebase&logoColor=white" alt="Firebase"/>
  <img src="https://img.shields.io/badge/PlatformIO-IDE-orange?style=for-the-badge&logo=platformio&logoColor=white" alt="PlatformIO"/>
  <img src="https://img.shields.io/badge/Android-Mobile%20App-brightgreen?style=for-the-badge&logo=android&logoColor=white" alt="Android"/>
</p>

<h1 align="center">🏠 HomeSecurity</h1>

<p align="center">
  <strong>IoT System for Remote Home Security and Monitoring</strong><br>
  <em>Sistema IoT pentru securitate și monitorizare la distanță a locuinței</em>
</p>

<p align="center">
  A smart, accessible, and reliable anti-intrusion security system built with ESP32, FreeRTOS, and Firebase Cloud integration, featuring a companion Android mobile application for real-time alerts and live video monitoring.
</p>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [System Architecture](#-system-architecture)
- [Features](#-features)
- [Hardware Components](#-hardware-components)
- [Pin Configuration](#-pin-configuration)
- [Software Architecture](#-software-architecture)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [Configuration](#-configuration)
- [LED Status Indicators](#-led-status-indicators)
- [Alert Logic Flow](#-alert-logic-flow)
- [Mobile Application](#-mobile-application)
- [Firebase Integration](#-firebase-integration)
- [Future Development](#-future-development)
- [Author](#-author)
- [License](#-license)

---

## 🎯 Overview

**HomeSecurity** is a comprehensive IoT-based anti-intrusion system designed as a diploma project at Transilvania University of Brașov. The system addresses the need for affordable, customizable home security solutions by leveraging modern embedded systems technology and cloud services.

### Key Highlights

- 🔐 **Multi-layered detection** using three different sensor types
- 📱 **Real-time push notifications** via Firebase Cloud Messaging
- 📹 **Live video streaming** integration via RTSP protocol
- ⚡ **Real-time operating system** (FreeRTOS) for concurrent task management
- 🌐 **Serverless architecture** using Firebase Cloud Functions
- 🔔 **Two-stage alert system** to minimize false alarms

---

## 🏗 System Architecture

The system implements a **distributed multi-tier architecture** typical of modern IoT solutions:

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                              SYSTEM ARCHITECTURE                            │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│   ┌─────────────┐     ┌─────────────────┐     ┌──────────────────────┐     │
│   │  EDGE TIER  │     │   CLOUD TIER    │     │    CLIENT TIER       │     │
│   │             │     │                 │     │                      │     │
│   │  ┌───────┐  │     │  ┌───────────┐  │     │  ┌────────────────┐  │     │
│   │  │ ESP32 │  │────▶│  │ Firebase  │  │────▶│  │ Android App    │  │     │
│   │  │       │  │     │  │ Cloud     │  │     │  │                │  │     │
│   │  └───────┘  │     │  │ Functions │  │     │  │ • Notifications│  │     │
│   │      │      │     │  └───────────┘  │     │  │ • Live Video   │  │     │
│   │      │      │     │       │         │     │  │ • Auth         │  │     │
│   │  ┌───┴───┐  │     │  ┌────┴────┐    │     │  └────────────────┘  │     │
│   │  │Sensors│  │     │  │   FCM   │    │     │          │           │     │
│   │  └───────┘  │     │  └─────────┘    │     │          │           │     │
│   │             │     │                 │     │    ┌─────┴─────┐     │     │
│   │  • Hall     │     │  • Auth         │     │    │  IP Camera │     │     │
│   │  • PIR      │     │  • Messaging    │     │    │   (RTSP)   │     │     │
│   │  • Radar    │     │  • Functions    │     │    └───────────┘     │     │
│   └─────────────┘     └─────────────────┘     └──────────────────────┘     │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Three-Tier Design

| Tier | Component | Responsibility |
|------|-----------|----------------|
| **Edge** | ESP32 + Sensors | Data acquisition, local processing, decision making, cloud communication |
| **Cloud** | Firebase | User authentication, notification orchestration, serverless logic |
| **Client** | Android App | User interface, alert reception, live video display |

---

## ✨ Features

### 🛡️ Security Features
- **Perimeter Detection**: Instant alerts when doors/windows are opened
- **Motion Detection**: PIR sensor for proximity movement detection
- **Presence Confirmation**: Doppler radar for sustained movement validation
- **False Alarm Reduction**: Two-stage alert logic with sensor fusion

### 📱 Mobile Features
- **Real-time Notifications**: Push alerts via Firebase Cloud Messaging
- **Live Video Streaming**: RTSP integration with TP-Link Tapo C200
- **User Authentication**: Email/password and Google Sign-In support
- **Dark/Light Theme**: User preference for visual comfort

### ⚙️ Technical Features
- **Concurrent Task Management**: FreeRTOS-based multitasking
- **Auto-reconnection**: Automatic WiFi recovery mechanism
- **Non-blocking Operations**: Efficient alarm handling without delays
- **Modular Codebase**: Clean separation of concerns

---

## 🔧 Hardware Components

### Bill of Materials

| Component | Model | Purpose | Quantity |
|-----------|-------|---------|----------|
| Microcontroller | ESP32 DOIT DevKit V1 | Central processing unit | 1 |
| Magnetic Sensor | KY-003 (Hall Effect) | Door/window open detection | 1 |
| PIR Sensor | HC-SR505 | Passive infrared motion detection | 1 |
| Radar Sensor | RCWL-0516 | Doppler microwave motion detection | 1 |
| Buzzer | KY-012 (Active) | Audible alarm | 1 |
| LEDs | 5mm (Various colors) | Visual status indicators | 5 |
| Resistors | 100Ω | Current limiting for LEDs | 5 |
| Power Supply | 2x 3.6V batteries | 7.2V source (regulated to 5V) | 1 set |
| IP Camera | TP-Link Tapo C200 | Live video streaming (RTSP) | 1 |

### Sensor Specifications

#### Hall Effect Sensor (KY-003)
- **Principle**: Detects magnetic field changes using Hall effect
- **Application**: Mounted on door frame with magnet on door
- **Output**: Digital HIGH/LOW based on magnet proximity

#### PIR Sensor (HC-SR505)
- **Principle**: Detects infrared radiation from warm bodies
- **Range**: Up to 3 meters
- **Calibration**: Requires 30-second warm-up period
- **Features**: Fresnel lens for multi-zone detection

#### Radar Sensor (RCWL-0516)
- **Principle**: Doppler effect microwave detection
- **Range**: Up to 7 meters
- **Advantages**: Works through non-metallic materials, immune to temperature/light
- **Application**: Interior presence confirmation

---

## 📌 Pin Configuration

### ESP32 GPIO Mapping

```
┌──────────────────────────────────────────────────────────────┐
│                    ESP32 DOIT DevKit V1                      │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  SENSORS                          LEDs                       │
│  ────────                         ────                       │
│  GPIO 33 ◄── Hall Sensor          GPIO 19 ──► Yellow LED     │
│  GPIO 21 ◄── PIR Sensor           GPIO 18 ──► Blue LED       │
│  GPIO 22 ◄── Radar Sensor         GPIO 23 ──► Red LED        │
│                                   GPIO 4  ──► Green LED      │
│  ALARM                            GPIO 13 ──► White LED      │
│  ─────                                                       │
│  GPIO 25 ──► Buzzer                                          │
│                                                              │
└──────────────────────────────────────────────────────────────┘
```

### Detailed Pin Table

| Pin | Component | Type | Description |
|-----|-----------|------|-------------|
| GPIO 33 | Hall Sensor | INPUT_PULLUP | Magnetic door sensor |
| GPIO 21 | PIR Sensor | INPUT | Motion detection |
| GPIO 22 | Radar Sensor | INPUT | Doppler motion detection |
| GPIO 25 | Buzzer | OUTPUT | Audio alarm |
| GPIO 19 | Yellow LED | OUTPUT | Hall sensor triggered |
| GPIO 18 | Blue LED | OUTPUT | PIR motion detected |
| GPIO 23 | Red LED | OUTPUT | Intrusion confirmed |
| GPIO 4 | Green LED | OUTPUT | System calibrated/ready |
| GPIO 13 | White LED | OUTPUT | WiFi connected |

---

## 💻 Software Architecture

### FreeRTOS Task Structure

The system utilizes FreeRTOS for real-time concurrent task management:

```
┌─────────────────────────────────────────────────────────────────────┐
│                       FreeRTOS TASK SCHEDULER                       │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│  Priority 4 (High)                                                  │
│  ┌─────────────────┐  ┌─────────────────┐  ┌────────────────────┐  │
│  │ HallSensor Task │  │ PIRSensor Task  │  │ HumanMovement Task │  │
│  │    2048 bytes   │  │   2048 bytes    │  │    6144 bytes      │  │
│  └─────────────────┘  └─────────────────┘  └────────────────────┘  │
│                                                                     │
│  Priority 3 (Medium)                                                │
│  ┌─────────────────┐  ┌─────────────────┐                          │
│  │ PIRCalibrate    │  │ RadarSensor     │                          │
│  │   1536 bytes    │  │   6144 bytes    │                          │
│  └─────────────────┘  └─────────────────┘                          │
│                                                                     │
│  Priority 2 (Low)                                                   │
│  ┌─────────────────┐                                               │
│  │ WiFiCheck Task  │                                               │
│  │   2048 bytes    │                                               │
│  └─────────────────┘                                               │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### Task Descriptions

| Task | Priority | Stack | Function |
|------|----------|-------|----------|
| `handleHallMovementTask` | 4 | 2048B | Monitors magnetic sensor, controls yellow LED |
| `handlePirMovementTask` | 4 | 2048B | Monitors PIR sensor, controls blue LED |
| `possibleHumanMovementDetectedTask` | 4 | 6144B | Orchestrates alert logic and notifications |
| `calibratePirSensorTask` | 3 | 1536B | Manages PIR 30-second calibration period |
| `handleRadarMovementTask` | 3 | 6144B | Monitors radar for presence confirmation |
| `WiFiCheckTask` | 2 | 2048B | Manages WiFi connection and auto-reconnect |

---

## 📁 Project Structure

```
HomeSecurity/
├── 📁 include/
│   ├── alarm.h              # Buzzer control interface
│   ├── firebase_notifier.h  # Firebase notification class
│   ├── hall_sensor.h        # Magnetic sensor interface
│   ├── led.h                # LED control functions
│   ├── microwave_sensor.h   # Radar sensor interface
│   ├── motion_logic.h       # Motion detection logic
│   ├── pir_sensor.h         # PIR sensor interface
│   └── wifi_manager.h       # WiFi management
├── 📁 src/
│   ├── main.cpp             # Application entry point
│   ├── alarm.cpp            # Buzzer implementation
│   ├── firebase_notifier.cpp # Firebase HTTP client
│   ├── hall_sensor.cpp      # Hall sensor implementation
│   ├── led.cpp              # LED control implementation
│   ├── microwave_sensor.cpp # Radar implementation
│   ├── motion_logic.cpp     # Core detection logic
│   ├── pir_sensor.cpp       # PIR implementation
│   └── wifi_manager.cpp     # WiFi implementation
├── 📁 lib/                  # External libraries
├── 📁 test/                 # Unit tests
├── 📁 .vscode/              # VS Code configuration
├── platformio.ini           # PlatformIO configuration
└── README.md                # This file
```

---

## 🚀 Getting Started

### Prerequisites

- [Visual Studio Code](https://code.visualstudio.com/)
- [PlatformIO IDE Extension](https://platformio.org/install/ide?install=vscode)
- ESP32 DOIT DevKit V1 board
- USB cable for programming

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/IonutMilitaru/HomeSecurity.git
   cd HomeSecurity
   ```

2. **Open in VS Code with PlatformIO**
   ```bash
   code .
   ```

3. **Install dependencies**
   
   PlatformIO will automatically install the required libraries defined in `platformio.ini`:
   - Firebase Arduino Client Library for ESP8266 and ESP32 v4.4.17

4. **Configure WiFi credentials** (see [Configuration](#-configuration))

5. **Build and Upload**
   ```bash
   # Using PlatformIO CLI
   pio run --target upload
   
   # Or use the PlatformIO IDE upload button
   ```

6. **Monitor Serial Output**
   ```bash
   pio device monitor --baud 115200
   ```

---

## ⚙️ Configuration

### WiFi Configuration

Edit `src/wifi_manager.cpp` to set your network credentials:

```cpp
char* WIFI_SSID = "YourNetworkName";
char* WIFI_PASSWORD = "YourPassword";
```

### Firebase Configuration

Edit `src/motion_logic.cpp` to configure your Firebase endpoint:

```cpp
FirebaseNotifier notifier("https://your-firebase-function-url.cloudfunctions.net/sendNotification");

const char* fcmToken = "your-device-fcm-token";
```

### Timing Parameters

| Parameter | Location | Default | Description |
|-----------|----------|---------|-------------|
| `WIFI_CONNECTION_TIMEOUT` | wifi_manager.cpp | 15000ms | WiFi connection timeout |
| `ALARM_DURATION` | alarm.h | 3000ms | Buzzer activation duration |
| PIR Calibration | pir_sensor.cpp | 30000ms | PIR warm-up period |
| Radar Confirmation | motion_logic.cpp | 2000ms | Sustained motion threshold |

---

## 💡 LED Status Indicators

| LED Color | State | Meaning |
|-----------|-------|---------|
| 🟢 **Green** | Solid ON | System calibrated and ready |
| ⚪ **White** | Solid ON | WiFi connected successfully |
| 🟡 **Yellow** | Solid ON | Hall sensor triggered (door opened) |
| 🔵 **Blue** | Solid ON | PIR motion detected |
| 🔴 **Red** | Solid ON | Intrusion confirmed by radar |

### Status Diagram

```
System Boot
    │
    ├──► [30 sec calibration] ──► 🟢 Green LED ON (System Ready)
    │
    └──► [WiFi connected] ──► ⚪ White LED ON
    
Runtime Monitoring
    │
    ├──► Hall Sensor HIGH ──► 🟡 Yellow LED ON + 🔔 Alarm + 📱 Notification
    │
    ├──► PIR Sensor HIGH ──► 🔵 Blue LED ON + 🔔 Alarm + 📱 Notification
    │
    └──► Radar (>2 sec) ──► 🔴 Red LED ON + 📱 Confirmation Notification
```

---

## 🔄 Alert Logic Flow

The system implements a **two-stage alert mechanism** to minimize false alarms:

### Stage 1: Perimeter Alert (Immediate Response)

```
┌─────────────────────────────────────────────────────────────┐
│                    PERIMETER ALERT                          │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   Hall Sensor ──┐                                           │
│       OR        ├──► 🔔 Buzzer (3 sec)                      │
│   PIR Sensor ───┘    📱 Warning Notification                │
│                      💡 Yellow/Blue LED                     │
│                                                             │
│   Message: "Mișcare detectată - Posibilă mișcare umană"     │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Stage 2: Presence Confirmation (Escalated Response)

```
┌─────────────────────────────────────────────────────────────┐
│                  PRESENCE CONFIRMATION                      │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│   Radar Active > 2 seconds ──► 📱 Confirmation Notification │
│                                🔴 Red LED ON                │
│                                                             │
│   Message: "Mișcare confirmată - Radarul a detectat         │
│            o mișcare continuă"                              │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Complete Flow Diagram

```
           ┌──────────────┐
           │  System Boot │
           └──────┬───────┘
                  │
                  ▼
     ┌────────────────────────┐
     │  PIR Calibration (30s) │
     │    Green LED OFF       │
     └────────────┬───────────┘
                  │
                  ▼
     ┌────────────────────────┐
     │   System Ready         │
     │   🟢 Green LED ON      │
     │   ⚪ White LED ON      │
     └────────────┬───────────┘
                  │
        ┌─────────┴─────────┐
        ▼                   ▼
┌───────────────┐   ┌───────────────┐
│ Hall Triggered│   │ PIR Triggered │
│ 🟡 Yellow LED │   │ 🔵 Blue LED   │
└───────┬───────┘   └───────┬───────┘
        │                   │
        └─────────┬─────────┘
                  ▼
     ┌────────────────────────┐
     │  STAGE 1: ALERT        │
     │  🔔 Buzzer (3 sec)     │
     │  📱 Warning Push       │
     └────────────┬───────────┘
                  │
                  ▼
     ┌────────────────────────┐
     │  Radar Monitoring      │
     │  (Parallel Task)       │
     └────────────┬───────────┘
                  │
          Motion > 2 sec?
          ╱             ╲
        YES              NO
         │                │
         ▼                ▼
┌─────────────────┐  ┌──────────────┐
│ STAGE 2:        │  │ Reset        │
│ CONFIRMATION    │  │ Wait for     │
│ 🔴 Red LED ON   │  │ next event   │
│ 📱 Confirm Push │  └──────────────┘
└─────────────────┘
```

---

## 📱 Mobile Application

The companion Android application is developed using modern technologies:

### Technology Stack

| Technology | Purpose |
|------------|---------|
| **Kotlin** | Primary programming language |
| **Jetpack Compose** | Declarative UI framework |
| **MVVM Architecture** | Separation of concerns |
| **Firebase Auth** | User authentication |
| **Firebase Cloud Messaging** | Push notifications |
| **LibVLC** | RTSP video streaming |

### Features

- 🔐 **Authentication**: Email/password and Google Sign-In
- 📬 **Push Notifications**: Real-time alerts with priority handling
- 📹 **Live Video**: RTSP streaming from TP-Link Tapo C200
- 🌓 **Theme Toggle**: Dark/Light mode support
- 🔄 **Reactive UI**: Automatic updates based on state changes

### App Screens

1. **Login Screen**: Email/password or Google authentication
2. **Home Screen**: Live video feed and system status
3. **Notification Display**: Alert history and details

---

## 🔥 Firebase Integration

### Architecture

```
┌─────────────┐         ┌─────────────────┐         ┌─────────────┐
│   ESP32     │  HTTP   │ Firebase Cloud  │   FCM   │   Mobile    │
│   Device    │ ──────► │   Function      │ ──────► │   App       │
└─────────────┘  POST   └─────────────────┘         └─────────────┘
```

### Services Used

| Service | Function |
|---------|----------|
| **Cloud Functions** | Serverless notification gateway |
| **Cloud Messaging (FCM)** | Push notification delivery |
| **Authentication** | User management |

### Notification Payload Structure

```json
{
  "title": "Mișcare detectată",
  "body": "Sistemul a detectat o posibilă mișcare umană.",
  "token": "device-fcm-token"
}
```

---

## 🔮 Future Development

### Planned Enhancements

| Feature | Description | Complexity |
|---------|-------------|------------|
| **Event Logging** | Store alerts in Cloud Firestore for historical analysis | Medium |
| **TinyML Integration** | On-device ML for person/pet classification (ESP32-CAM) | High |
| **VPN/WebRTC** | Secure video streaming without port forwarding | High |
| **Battery Backup** | Li-Po integration with deep sleep optimization | Medium |
| **Multi-Node System** | ESP-NOW mesh network for whole-home coverage | High |
| **Voice Assistant** | Google Home/Alexa integration | Medium |

---

## 👨‍💻 Author

**Militaru Ionuț-Daniel**

- 🎓 Diploma Project - Transilvania University of Brașov
- 📚 Faculty of Electrical Engineering and Computer Science
- 🎯 Information Technology Program
- 📅 Graduation: 2025

### Academic Supervisor

**Assoc. Prof. Dr. Eng. MĂCEȘANU Gigel**

---

## 📚 References

1. Espressif Systems. *ESP32 Series Datasheet*. 2023.
2. Richard Barry. *Mastering the FreeRTOS Real Time Kernel*. Real Time Engineers Ltd., 2016.
3. Google. *Firebase Documentation*. firebase.google.com/docs
4. IETF. *RFC 2326: Real Time Streaming Protocol (RTSP)*. 1998.
5. PlatformIO. *Official Documentation*. platformio.org

---

## 📄 License

This project was developed as an academic diploma project at Transilvania University of Brașov, Romania.

---

<p align="center">
  <strong>🏠 HomeSecurity - Protecting What Matters Most</strong><br>
  <em>Made with ❤️ in Brașov, Romania</em>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Status-Complete-success?style=flat-square" alt="Status"/>
  <img src="https://img.shields.io/badge/Academic-Diploma%20Project-blue?style=flat-square" alt="Academic"/>
  <img src="https://img.shields.io/badge/Year-2025-informational?style=flat-square" alt="Year"/>
</p>
