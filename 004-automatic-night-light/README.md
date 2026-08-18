# 🌙 Day 04 — Automatic Night Light

> A simple automatic lighting system built with Arduino and an LDR.

This project turns an LED into a basic **automatic night light**.

The Arduino continuously measures the amount of light in the environment. When the environment becomes dark, the LED turns on automatically.

---

## ⚡ How It Works

```text
        ☀️ / 🌙
           │
           ▼
      ┌─────────┐
      │   LDR   │
      └────┬────┘
           │
           ▼
       📥 ADC / A0
           │
           ▼
      🧠 Threshold
        Decision
        /      \
     DARK      LIGHT
      │           │
      ▼           ▼
   💡 ON        OFF
```

---

## 🎯 Objective

Build a small system that can detect ambient light and automatically control an LED.

The project introduces a very common embedded-systems pattern:

> **Sense → Decide → Act**

---

## 🧠 Concepts

* Analog Input
* LDR / Light Sensor
* ADC
* Voltage Divider
* Threshold-based decision making
* PWM Output
* `analogRead()`
* `analogWrite()`
* `Serial Monitor`
* Conditional logic

---

## 🛠️ Hardware

| Component     | Quantity |
| ------------- | -------: |
| Arduino UNO   |        1 |
| LDR           |        1 |
| 10kΩ Resistor |        1 |
| LED           |        1 |
| 220Ω Resistor |        1 |
| Breadboard    |        1 |
| Jumper Wires  |  Several |

---

## 🔌 Pin Configuration

### LDR

```text
5V  ─── LDR ───┬── A0
               │
              10kΩ
               │
              GND
```

### LED

```text
D9 ─── 220Ω ─── LED ─── GND
```

---

## 💻 Code

```cpp
const int LDR_PIN = A0;
const int LED_PIN = 9;

const int LIGHT_THRESHOLD = 500;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int lightValue = analogRead(LDR_PIN);

    Serial.print("Light: ");
    Serial.println(lightValue);

    if (lightValue < LIGHT_THRESHOLD) {
        analogWrite(LED_PIN, 255);
    } else {
        analogWrite(LED_PIN, 0);
    }

    delay(100);
}
```

---

## 🔍 Understanding the Logic

The LDR changes its resistance depending on the amount of light.

The Arduino reads the resulting voltage on `A0`:

```text
0 ───────────────────────── 1023
│                            │
Lower reading             Higher reading
```

With this circuit, a lower reading means the environment is darker.

The program therefore checks:

```cpp
if (lightValue < LIGHT_THRESHOLD)
```

When the value goes below the threshold, the LED is turned on.

---

## 🎚️ Adjusting the Threshold

The current threshold is:

```cpp
const int LIGHT_THRESHOLD = 500;
```

You can watch the value in the **Serial Monitor** and choose a better threshold for your environment.

For example:

```text
Dark room   → 250
Normal room → 550
Bright room → 850
```

These values are only examples. The actual readings depend on the LDR, resistor, wiring, and lighting conditions.

---

## 🚀 Possible Improvements

This project can become much more advanced:

* 🌅 Gradually increase LED brightness
* 🎚️ Use PWM instead of simple ON/OFF
* 📊 Display light level on an OLED
* 💡 Control an RGB LED
* 🧠 Add hysteresis to prevent rapid switching
* 📡 Send light data over Wi-Fi using ESP32
* 🌐 Create a web-based light monitor
* 🏠 Turn it into a complete smart-light system

---

## 📈 Progress

| Day    | Project                      | Main Concept          |
| ------ | ---------------------------- | --------------------- |
| 01     | LED Blink                    | Digital Output        |
| 02     | Button Controlled LED        | Digital Input         |
| 03     | Potentiometer Controlled LED | Analog Input + PWM    |
| **04** | **Automatic Night Light**    | **Sensor + Decision** |

---

## 🧩 Embedded Pattern

This project introduces one of the most important patterns in embedded systems:

```text
SENSOR
   ↓
READ DATA
   ↓
PROCESS
   ↓
DECISION
   ↓
ACTUATOR
```

The same structure appears in much larger systems such as:

* Smart lighting
* Temperature controllers
* Security systems
* Industrial automation
* IoT devices

---

## 🔮 Next Step

The next projects will start combining multiple components and introducing more realistic embedded-system behavior.

**Build → Measure → Decide → Act.** ⚡

---

## 📜 License

This project is licensed under the MIT License.
