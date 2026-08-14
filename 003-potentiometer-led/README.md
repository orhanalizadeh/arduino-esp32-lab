# 003 — Potentiometer Controlled LED

> Turn a potentiometer and control the brightness of an LED in real time. 💡

This project introduces two important embedded systems concepts:

**Analog Input** and **PWM Output**

Instead of simply turning an LED ON or OFF, the brightness is continuously adjusted according to the potentiometer position.

---

## 🎯 Objective

The system reads the potentiometer value and converts it into an LED brightness level.

```text
Potentiometer
      │
      ▼
 Analog Input
      │
      ▼
   Processing
      │
      ▼
   PWM Output
      │
      ▼
   LED Brightness
```

---

## 🧠 Concepts

* Analog Input
* ADC
* PWM
* `analogRead()`
* `analogWrite()`
* `map()`
* GPIO
* Real-time value conversion

---

## 🛠️ Hardware

| Component     | Quantity |
| ------------- | -------: |
| Arduino UNO   |        1 |
| Potentiometer |        1 |
| LED           |        1 |
| 220Ω Resistor |        1 |
| Breadboard    |        1 |
| Jumper Wires  |  Several |

---

## 🔌 Wiring

### Potentiometer

| Potentiometer Pin | Arduino |
| ----------------- | ------- |
| VCC               | 5V      |
| GND               | GND     |
| Wiper             | A0      |

### LED

| LED         | Arduino                  |
| ----------- | ------------------------ |
| Anode (+)   | D9 through 220Ω resistor |
| Cathode (-) | GND                      |

---

## 💻 Code

```cpp
const int POT_PIN = A0;
const int LED_PIN = 9;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int potValue = analogRead(POT_PIN);

    int brightness = map(potValue, 0, 1023, 0, 255);

    analogWrite(LED_PIN, brightness);
}
```

---

## ⚙️ How It Works

### 1. Read the potentiometer

```cpp
int potValue = analogRead(POT_PIN);
```

On an Arduino UNO, `analogRead()` returns a value from:

```text
0 → 1023
```

The value changes depending on the voltage at A0.

---

### 2. Convert the value

```cpp
int brightness = map(potValue, 0, 1023, 0, 255);
```

The potentiometer range is converted into the PWM range.

```text
Analog Input          PWM Output

0       ───────────►   0
512     ───────────►   127
1023    ───────────►   255
```

---

### 3. Control LED brightness

```cpp
analogWrite(LED_PIN, brightness);
```

The Arduino generates a PWM signal on D9.

A higher PWM value produces a higher average power level and therefore a brighter LED.

---

## 🔄 Behavior

```text
Potentiometer at minimum
            ↓
        LED OFF

            ↓

Potentiometer in middle
            ↓
      LED Medium Brightness

            ↓

Potentiometer at maximum
            ↓
        LED Full Brightness
```

---

## 🚀 Possible Improvements

This project can later evolve into:

* Two potentiometers controlling two LEDs
* RGB LED color control
* Potentiometer-controlled motor speed
* OLED display for the ADC value
* Serial Monitor visualization
* Digital filtering / smoothing
* ESP32 ADC version
* PWM frequency control

---

## 📈 Project Progress

| Day | Project                      | Main Concept       |
| --- | ---------------------------- | ------------------ |
| 01  | LED Blink                    | Digital Output     |
| 02  | Button Controlled LED        | Digital Input      |
| 03  | Potentiometer Controlled LED | Analog Input + PWM |

---

## 📜 License

This project is licensed under the MIT License.
