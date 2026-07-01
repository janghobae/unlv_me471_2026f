#include <Arduino.h>

int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
    Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0) 
    {
        String command = Serial.readString();

        command.trim();
        
        if (command == String("on"))
        {
            digitalWrite(ledPin, HIGH);
        }
        else if (command == String("off"))
        {
            digitalWrite(ledPin, LOW);
        }
    }
}