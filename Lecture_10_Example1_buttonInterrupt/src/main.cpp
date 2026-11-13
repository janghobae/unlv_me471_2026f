#include <Arduino.h>

int buttonPin = 19;

void buttonISR();
volatile int buttonCount = 0;
volatile bool buttonPressed = false;

void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);
}

void loop() {
    if (buttonPressed == true)
    {
        Serial.println(buttonCount);
        buttonPressed = false;
    }
    delay(100);
}

void buttonISR() {
    buttonCount++;
    buttonPressed = true;
}
