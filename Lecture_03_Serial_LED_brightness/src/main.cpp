#include <Arduino.h>

int ledPin = 13;
String command;
int command_int = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0) 
    {
        command = Serial.readString();
        command_int = command.toInt();
    }
    analogWrite(ledPin, command_int);
}