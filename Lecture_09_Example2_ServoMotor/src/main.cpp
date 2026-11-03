#include <Arduino.h>
#include <Servo.h>

Servo servo;
int servoPin = A0;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  servo.write(0);
  delay(500);
  servo.write(180);
  delay(500);
}