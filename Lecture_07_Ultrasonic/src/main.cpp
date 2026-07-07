#include <Arduino.h>

int trigPin = 14;
int echoPin = 15;
int ledRed = 16;
int ledGrn = 17;

long duration;
long distance;

void setup() {
    pinMode(ledRed, OUTPUT);
    pinMode(ledGrn, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.println(distance);
    if (distance > 10)
    {
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGrn, HIGH);
    }
    else
    {
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGrn, LOW);
    }
    delay(100);
}
