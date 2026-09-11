#include <Arduino.h>

int ledPin = 19;

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
        
        if (command.toInt() != 0)
        {
            analogWrite(ledPin, command.toInt());
        }
        else
        {
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
}