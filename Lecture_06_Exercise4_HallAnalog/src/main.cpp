#include <Arduino.h>

int hallPin = A0;
int hallValue;
int ledPin = 19;

void setup() {
    pinMode(hallPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    hallValue = analogRead(hallPin);
    if (hallValue < 400 || hallValue > 700)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }

    delay(100);
}
