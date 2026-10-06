#include <Arduino.h>

int potPin = A0;
int LEDPin = 19;
int potValue = 0;

void setup() {
    pinMode(potPin, INPUT);
    pinMode(LEDPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    potValue = 1023 - analogRead(potPin);
    analogWrite(LEDPin, potValue/8);
    Serial.println(potValue);
    delay(100);
}
