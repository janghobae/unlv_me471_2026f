#include <Arduino.h>

int ledR = 19;
int sw = 18;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(sw, INPUT);
}

void loop() {
  if (digitalRead(sw) == LOW)
  {
    digitalWrite(ledR, HIGH);
  }
  else
  {
    digitalWrite(ledR, LOW);
  }
}