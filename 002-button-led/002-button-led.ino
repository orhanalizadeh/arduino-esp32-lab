// 002

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
