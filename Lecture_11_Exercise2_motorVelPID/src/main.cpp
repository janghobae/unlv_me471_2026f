#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

float contInput = 0;

float desVel = 0;
float currVel = 0;
float prevVel = 0;

int currPos = 0;
int prevPos = 0;

float e_P = 0;
float e_I = 0;
float e_D = 0;

float k_P = 0.05;
float k_I = 0.04;
float k_D = 0.0002;

String command;

void setup() {
  controller.begin();
  Serial.begin(115200);
  Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0)
    {
        command = Serial.readString();
        command.trim();
        desVel = command.toInt();
    }
    
    currPos = encoder1.getRawCount();

    currVel = (currPos - prevPos) / 0.01;

    e_P = desVel - currVel;
    e_I = e_I + (desVel - currVel) * 0.01;
    e_D = 0 - (currVel - prevVel) / 0.01;

    contInput = k_P * e_P + k_I * e_I + k_D * e_D;

    if (contInput > 100)
    {
        contInput = 100.0;
    }
    else if (contInput < -100)
    {
        contInput = -100.0;
    }
    M1.setDuty(contInput);

    prevPos = currPos;
    prevVel = currVel;

    Serial.println(currVel);
    delay(10);
}
