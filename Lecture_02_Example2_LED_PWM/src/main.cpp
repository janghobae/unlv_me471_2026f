#include <Arduino.h>

int ledPin = 19;
int ledPWM = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(ledPWM = 0; ledPWM <= 255; ledPWM += 5)
  {
    analogWrite(ledPin, ledPWM);
    delay(10);
  }
  for(ledPWM = 255; ledPWM >= 0; ledPWM -= 5)
  {
    analogWrite(ledPin, ledPWM);
    delay(10);
  }
}