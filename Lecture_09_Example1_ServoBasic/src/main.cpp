#include <Arduino.h>
#include <Servo.h>

Servo servo;
int servoPin = 19;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  servo.write(0);
  delay(500);
  servo.write(90);
  delay(500);
}