# 🟢 Day 01 — LED Blink

> My first step into Arduino & Embedded Systems 🚀

A simple LED blinking project built with Arduino C++.
This project introduces the fundamentals of **GPIO control** and the basic structure of an Arduino program.

---

## 🎯 Objective

The goal of this project is to control a digital output and make an LED:

**ON → 1 second → OFF → 1 second → repeat**

It's a tiny project, but it introduces one of the most important concepts in embedded systems:

> **Controlling hardware with software.**

---

## 🧠 Concepts Learned

* GPIO
* Digital output
* `pinMode()`
* `digitalWrite()`
* `delay()`
* `setup()` and `loop()`
* Basic embedded programming structure

---

## 🔌 Circuit

For an external LED:

```text
Arduino GPIO
     │
     │
   220Ω
     │
     │
    LED
     │
     │
    GND
```

### Connections

| Component       | Connection                |
| --------------- | ------------------------- |
| LED Anode (+)   | GPIO / LED pin            |
| LED Cathode (-) | GND                       |
| Resistor        | 220Ω between GPIO and LED |

> A resistor is used to limit the current flowing through the LED.

---

## 💻 Code

```cpp
const int LED_PIN = LED_BUILTIN;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);

    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
```

---

## ⚙️ How It Works

### `setup()`

Runs once when the board starts.

```cpp
pinMode(LED_PIN, OUTPUT);
```

This configures the LED pin as a digital output.

### `loop()`

Runs continuously.

```cpp
digitalWrite(LED_PIN, HIGH);
```

Turns the LED on.

```cpp
delay(1000);
```

Waits for 1 second.

```cpp
digitalWrite(LED_PIN, LOW);
```

Turns the LED off.

Then the cycle repeats forever.

---

## 🚀 Possible Improvements

This project can later be extended with:

* Adjustable blink speed
* Button-controlled LED
* Multiple LEDs
* Non-blocking timing with `millis()`
* Morse code generator
* LED status indicator
* State-machine based control

---

## 📈 Progress

**Day 01 / Arduino & ESP32 Daily Projects**

```text
GPIO █████░░░░░  Beginner
C++  ████░░░░░░  Beginner
Git  ███░░░░░░░  Beginner
```

More projects coming every day. 🔥

---

## 📜 License

This project is open-source and available for learning and experimentation.

---

Made With ❤ By Orhan Alizadeh .