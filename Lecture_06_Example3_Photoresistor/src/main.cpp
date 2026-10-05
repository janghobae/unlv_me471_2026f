#include <Arduino.h>

int photoResist = A0;
int prValue = 0;

void setup() {
    pinMode(photoResist, INPUT);
    Serial.begin(9600);
}

void loop() {
    prValue = analogRead(photoResist);
    Serial.println(prValue);
}
