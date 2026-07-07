#include <Arduino.h>

int hallPin = A0;
int hallValue;

void setup() {
    pinMode(hallPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    hallValue = analogRead(hallPin);
    Serial.println(hallValue);
}
