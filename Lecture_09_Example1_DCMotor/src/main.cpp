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

    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);

    if (Serial.available() > 0)
    {
        command = Serial.readString();
        command.trim();
        commandPWM = command.toInt();
    }

    analogWrite(motorPWM, commandPWM);
}