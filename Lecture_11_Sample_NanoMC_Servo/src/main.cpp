#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

String command = "";
int des_angle = 0;

void setup() {
    controller.begin();
    Serial.begin(115200);
    Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0) 
    {
        command = Serial.readString();
        des_angle = command.toInt();
        Serial.println(des_angle);
    }

    servo1.setAngle(des_angle);
}
