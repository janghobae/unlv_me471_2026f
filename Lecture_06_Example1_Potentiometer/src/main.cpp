#include <Arduino.h>

int potPin = A0;
int potValue = 0;

void setup() {
    pinMode(potPin, INPUT);
    Serial.begin(115200);
}

void loop() {
    potValue = analogRead(potPin);
    Serial.println(potValue);
    delay(100);
}
