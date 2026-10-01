#include <Arduino.h>

int photoResist = A0;
int ledPin = 15;
int prValue = 0;

void setup() {
    pinMode(photoResist, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    prValue = analogRead(photoResist);
    Serial.println(prValue);
    if (prValue > 400)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}
