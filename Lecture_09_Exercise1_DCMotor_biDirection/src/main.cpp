#include <Arduino.h>

int inA = 16;
int inB = 17;
int motorPWM = A0;
int commandPWM = 0;
String command;

void setup() {
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    pinMode(motorPWM, OUTPUT);
    Serial.begin(115200);
}

void loop() {

    if (Serial.available() > 0)
    {
        command = Serial.readString();
        command.trim();
        commandPWM = command.toInt();
    }

    if (commandPWM >= 0)
    {
        digitalWrite(inA, HIGH);
        digitalWrite(inB, LOW);
    }
    else
    {
        digitalWrite(inA, LOW);
        digitalWrite(inB, HIGH);
        commandPWM = -commandPWM;
    }

    analogWrite(motorPWM, commandPWM);
}