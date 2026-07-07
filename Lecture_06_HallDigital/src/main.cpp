#include <Arduino.h>

int hallPin = 14;
int ledPin = 15;

void setup() {
    pinMode(hallPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    bool mag = digitalRead(hallPin);
    Serial.println(mag);
    if (mag == 1)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}
