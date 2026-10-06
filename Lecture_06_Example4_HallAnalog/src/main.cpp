#include <Arduino.h>

int hallPin = A0;
int hallValue;

void setup() {
    pinMode(hallPin, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
    hallValue = digitalRead(hallPin);
    Serial.println(hallValue);
    delay(100);
}
