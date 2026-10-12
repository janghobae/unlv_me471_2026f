#include <Arduino.h>

int trigPin = 14;
int echoPin = 15;

long duration;
float distance;

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
    distance = (duration/2) * (0.034);
    Serial.println(distance);
    delay(100);
}
