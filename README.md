# 🌧️ Arduino Smart Rain Detection & Weather Station with I2C LCD and Touch Acknowledge

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-00599C.svg?logo=c%2B%2B&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status: Tested](https://img.shields.io/badge/Hardware%20Status-Tested%20%26%20Verified-brightgreen.svg)]()

Intelligent meteorological precipitation alert systems for Arduino. From basic rain droplet sensor testing to a complete interactive weather alert station featuring a 16x2 I2C LCD status screen, continuous acoustic buzzer alarm, and a capacitive touch silence/acknowledgment button.

---

## 📋 Included Implementations

| Directory | Description | Features |
| :--- | :--- | :--- |
| [`basic_rain_sensor/`](basic_rain_sensor/) | Minimalist precipitation threshold trigger | Rain Board (`Pin 2`), Onboard LED (`Pin 13`) |
| [`smart_rain_detector_touch_buzzer_lcd/`](smart_rain_detector_touch_buzzer_lcd/) | Full interactive rain alert station | Rain Sensor (`Pin 2`), TTP223 Touch (`Pin 3`), Buzzer (`Pin 4`), 16x2 I2C LCD (`0x27`) |

---

## 🛠️ Hardware Requirements & Bill of Materials (BOM)

| Component | Specification | Quantity |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno R3 / R4 or Nano | 1 |
| **Raindrop Sensor Board** | FC-37 / YL-83 sensing board + LM393 comparator module | 1 |
| **Capacitive Touch Sensor** | TTP223 digital capacitive touch switch module | 1 |
| **16x2 Character LCD** | 1602 LCD with PCF8574 I2C adapter backpack | 1 |
| **Piezo Buzzer** | 5V Active Piezo Buzzer | 1 |
| **Jumper Wires** | Male-to-Female and Male-to-Male Dupont jumpers | 1 set |

---

## 🔌 Circuit Pinout & Wiring

### Smart Rain Station (`smart_rain_detector_touch_buzzer_lcd`):

| Component Pin | Arduino Uno / Nano Pin | Description |
| :--- | :--- | :--- |
| **Rain Sensor DO (Digital Out)** | Digital Pin 2 | Active LOW on droplet detection |
| **TTP223 Touch Sensor SIG** | Digital Pin 3 | Active HIGH on finger contact |
| **Piezo Buzzer (+)** | Digital Pin 4 | High-decibel audio alert |
| **I2C LCD SDA** | Analog Pin A4 | Serial Data Bus |
| **I2C LCD SCL** | Analog Pin A5 | Serial Clock Bus |
| **All Module VCC Pins** | 5V Rail | Regulated +5V Power |
| **All Module GND Pins** | GND Rail | Common System Ground |

---

## ⚙️ Interactive State Behavior

```mermaid
stateDiagram-v2
    [*] --> READY: System Init
    READY --> RAIN_ALARM: Rain Detected (DO = LOW)
    state RAIN_ALARM {
        [*] --> Buzzing
        --> ScreenAlert: "Rain is falling"
    }
    RAIN_ALARM --> USER_ACK: Touch Sensor Pressed (SIG = HIGH)
    USER_ACK --> READY: Screen: "You're welcome" (3s Delay)
```

1. **System Ready**: LCD initializes with startup banner; sensor monitors ambient droplet board.
2. **Rain Alert**: When water droplets bridge the trace conductors, comparator pulls Pin 2 `LOW`. LCD immediately alerts `"Rain is falling"` and acoustic buzzer sounds continuously.
3. **Capacitive Touch Silence**: Touching the TTP223 sensor immediately terminates the buzzer tone and responds politely on the LCD: `"You're welcome"`.

---

## 📦 Required Arduino Libraries

- `LiquidCrystal I2C` (by Marco Schwartz / Frank de Brabander)
- `Wire` (built-in AVR library)

---

## 🚀 Installation & Upload

1. Clone repository:
   ```bash
   git clone https://github.com/youniquestar/arduino-smart-rain-detector.git
   ```
2. Open [`smart_rain_detector_touch_buzzer_lcd/smart_rain_detector_touch_buzzer_lcd.ino`](smart_rain_detector_touch_buzzer_lcd/smart_rain_detector_touch_buzzer_lcd.ino).
3. Connect your Arduino board via USB and hit **Upload**.

---

## 📜 License

Open-source under the [MIT License](LICENSE).
