#include <Arduino.h>

int thermistorPin = A0;
int tempValue = 0;

void setup() {
    pinMode(thermistorPin, INPUT);
    Serial.begin(115200);
}

void loop() {
    tempValue = analogRead(thermistorPin);
    Serial.println(tempValue);
    delay(100);
}
