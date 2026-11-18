#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

int contInput = 0;
int desPos = 0;
int currPos = 0;
int prevPos = 0;

float e_P = 0;
float e_I = 0;
float e_D = 0;

float k_P = 0.3;
float k_I = 0.05;
float k_D = 0.01;

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
        desPos = command.toInt();
    }
    
    currPos = encoder1.getRawCount();

    e_P = desPos - currPos;
    e_I = e_I + (desPos - currPos) * 0.01;
    e_D = 0 - (currPos - prevPos) / 0.01;

    contInput = k_P * e_P + k_I * e_I + k_D * e_D;

    if (contInput > 100)
    {
        contInput = 100;
    }
    else if (contInput < -100)
    {
        contInput = -100;
    }
    M1.setDuty(contInput);

    prevPos = currPos;

    Serial.println(currPos);
    delay(10);
}
