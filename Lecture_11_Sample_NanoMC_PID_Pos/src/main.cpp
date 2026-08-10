#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

String command = "";

int des_pos = 0;

float k_P = 0.2;
float k_I = 0.01;
float k_D = 0.02;

void setup() {
    controller.begin();
    Serial.begin(115200);
    Serial.setTimeout(10);

    M1.setDuty(0);
    M2.setDuty(0);
    M3.setDuty(0);
    M4.setDuty(0);

    pid1.setControlMode(CL_POSITION);
    pid1.setGains(k_P, k_I, k_D);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (Serial.available() > 0) 
        {
            command = Serial.readString();
            des_pos = command.toInt();
            Serial.println(des_pos);
        }

    pid1.setSetpoint(TARGET_POSITION, des_pos);
    delay(50);
    Serial.print("encoder: ");
    Serial.println(encoder1.getRawCount());
}
