#include <Arduino.h>

int photoResist = A0;
int prValue = 0;

int potPin = A1;
int potValue = 0;

int ledPin = 19;

void setup() {
    pinMode(photoResist, INPUT);
    pinMode(potPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    prValue = analogRead(photoResist);
    potValue = analogRead(potPin);

    if (prValue < potValue)
    {
        digitalWrite(ledPin, LOW);
    }
    else
    {
        digitalWrite(ledPin, HIGH);
    }
    delay(100);
}
