#include <Arduino.h>

int tempSensorPin = A0;
int temp = 0;

void setup() {
  analogReadResolution(12);
  pinMode(tempSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  temp = analogRead(tempSensorPin);
  Serial.println(temp);
}
