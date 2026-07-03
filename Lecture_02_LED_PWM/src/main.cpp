#include <Arduino.h>

int ledPin = 19;
int i = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(i = 0; i <= 255; i += 5)
  {
    analogWrite(ledPin, i);
    delay(10);
  }
  for(i = 255; i >= 0; i -= 5)
  {
    analogWrite(ledPin, i);
    delay(10);
  }
}