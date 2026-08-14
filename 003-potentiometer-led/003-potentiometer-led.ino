// 003

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

