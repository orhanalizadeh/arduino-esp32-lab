// 004

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