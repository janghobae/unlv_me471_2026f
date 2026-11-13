#include <Arduino.h>

int pinA = 19;
int pinB = 18;

volatile long encoderCount = 0;

void readEncoder();

void setup() {
    Serial.begin(115200);
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    attachInterrupt(digitalPinToInterrupt(pinA), readEncoder, CHANGE);
}

void loop() {
    Serial.println(encoderCount);
}


void readEncoder() {
    int AState = digitalRead(pinA);
    int BState = digitalRead(pinB);

    if (AState != BState) 
    {
        encoderCount++;
    } 
    else 
    {
        encoderCount--;
    }
}