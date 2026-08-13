# 🔵 Day 02 — Button Controlled LED

> Control an LED with a physical button using digital input and output.

This project demonstrates one of the most fundamental concepts in embedded systems:

**Reading an input → Processing the state → Controlling an output**

---

## 🎯 Objective

The goal is simple:

```text
Button Pressed   →   LED ON
Button Released  →   LED OFF
```

This project builds on the GPIO concepts introduced in **Day 01 — LED Blink**.

---

## 🧠 Concepts

* Digital Input
* Digital Output
* GPIO
* `digitalRead()`
* `digitalWrite()`
* `pinMode()`
* `INPUT_PULLUP`
* Conditional statements
* Basic hardware interaction

---

## 🔌 Hardware

### Components

| Component    | Quantity |
| ------------ | -------: |
| Arduino UNO  |        1 |
| Push Button  |        1 |
| Jumper Wires |        2 |
| Breadboard   |        1 |

No external resistor is required for the button because the Arduino's internal pull-up resistor is enabled.

---

## 🔧 Wiring

```text
             Arduino UNO

              D2
               │
               │
          ┌────┴────┐
          │ BUTTON  │
          └────┬────┘
               │
              GND


        Built-in LED
             D13
              │
              ▼
             LED
```

### Connections

| Component    | Arduino       |
| ------------ | ------------- |
| Button       | D2            |
| Button       | GND           |
| Built-in LED | `LED_BUILTIN` |

---

## 💻 Code

```cpp
const int LED_PIN = LED_BUILTIN;
const int BUTTON_PIN = 2;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == LOW) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}
```

---

## ⚙️ How It Works

### 1. Define the pins

```cpp
const int LED_PIN = LED_BUILTIN;
const int BUTTON_PIN = 2;
```

The built-in LED is used as the output and digital pin 2 is used as the button input.

### 2. Configure the pins

```cpp
pinMode(LED_PIN, OUTPUT);
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

The LED is configured as an output.

The button uses the Arduino's internal pull-up resistor.

This means:

```text
Button released → HIGH
Button pressed  → LOW
```

### 3. Read the button

```cpp
int buttonState = digitalRead(BUTTON_PIN);
```

The current state of the button is stored in `buttonState`.

### 4. Control the LED

```cpp
if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);
}
```

If the button is pressed, the LED turns on.

Otherwise:

```cpp
digitalWrite(LED_PIN, LOW);
```

The LED turns off.

---

## 🔄 Logic

```text
        ┌─────────────┐
        │ Read Button │
        └──────┬──────┘
               │
               ▼
        ┌─────────────┐
        │ Button LOW? │
        └──────┬──────┘
          YES  │  NO
           │   │
           ▼   ▼
        LED ON  LED OFF
           │   │
           └───┴──────► Repeat
```

---

## 🚀 Possible Improvements

Future versions could add:

* Toggle LED with one button press
* Multiple buttons
* Button debouncing
* Long-press detection
* Multiple LEDs
* Button-controlled PWM brightness
* Interrupt-based button handling

---

## 📈 Progress

| Project | Topic                 | Status |
| ------- | --------------------- | ------ |
| 001     | LED Blink             | ✅      |
| 002     | Button Controlled LED | ✅      |

---

## 🧩 Next Step

The next project will introduce another important concept:

**Analog Input → Processing → Output**

---

## 📜 License

This project is licensed under the MIT License.

---

Made With ❤ By Orhan Alizadeh .