#include <Arduino.h>

int buttonPin = 19;
int ledPin = 18;

void buttonISR();
bool blinkFast = false;

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    if (blinkFast == true)
    {
        delay(100);
    }
    else
    {
        delay(500);
    }
    digitalWrite(ledPin, LOW);
    if (blinkFast == true)
    {
        delay(100);
    }
    else
    {
        delay(500);
    }
}

void buttonISR() {
    if (blinkFast == false)
    {
        blinkFast = true;
    }
    else
    {
        blinkFast = false;
    }
}
