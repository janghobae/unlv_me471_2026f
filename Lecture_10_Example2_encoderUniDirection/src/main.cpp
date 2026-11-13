#include <Arduino.h>

int pinA = 19;

volatile long encoderCount = 0;

void pinACount();

void setup() {
    Serial.begin(115200);
    pinMode(pinA, INPUT);
    attachInterrupt(digitalPinToInterrupt(pinA), pinACount, RISING);
}

void loop() {
    Serial.println(encoderCount);
    delay(50);
}


void pinACount() {
    encoderCount++;
}
