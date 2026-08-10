#include <Arduino.h>

int clkPin = 19;
int dtPin = 18;

int encoderCount = 0;

void readEncoder();

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);

    attachInterrupt(digitalPinToInterrupt(clkPin), readEncoder, CHANGE);
}

void loop() {
    // put your main code here, to run repeatedly:
    Serial.println(encoderCount);
}


void readEncoder() {
  // Read current states of the channels
  int clkState = digitalRead(clkPin);
  int dtState = digitalRead(dtPin);

  // If the states are different, the encoder is turning clockwise
  if (clkState != dtState) {
    encoderCount++;
  } else {
    // If the states are the same, the encoder is turning counterclockwise
    encoderCount--;
  }
}