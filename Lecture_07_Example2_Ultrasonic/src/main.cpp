#include <Arduino.h>

int trigPin = 14;
int echoPin = 15;

long duration;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    Serial.println(duration);
    delay(100);
}
