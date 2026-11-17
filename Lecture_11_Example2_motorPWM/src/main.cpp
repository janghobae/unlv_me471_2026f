#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

int motorPWM = 0;
String command;

void setup() {
  controller.begin();
  Serial.begin(115200);
}

void loop() {
    if (Serial.available() > 0)
    {
        command = Serial.readString();
        command.trim();
        motorPWM = command.toInt();
    }
    
    M1.setDuty(motorPWM);
    delay(100);
}
