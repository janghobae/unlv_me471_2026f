#include <Arduino.h>

int receiverPin = A0;
int transPin = 19;
int IRValue;

void setup() {
    pinMode(receiverPin, INPUT);
    pinMode(transPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(transPin, HIGH);
    IRValue = digitalRead(receiverPin);
    Serial.println(IRValue);
    delay(100);
}
