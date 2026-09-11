#include <Arduino.h>

int ledPin = 19;
bool ledStatus = false;

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
            if (ledStatus == false)
            {
                Serial.println("LED is off! Turn it on first!");
            }
            else if (ledStatus == true && (command.toInt() > 0 && command.toInt() <= 255))
            {
                analogWrite(ledPin, command.toInt());
            }
            else
            {
                Serial.println("Number is out of range!");
            }
        }
        else
        {
            if (command == String("on"))
            {
                analogWrite(ledPin, 255);
                ledStatus = true;
            }
            else if (command == String("off"))
            {
                analogWrite(ledPin, 0);
                ledStatus = false;
            }
            else
            {
                Serial.println("Command not Valid!");
            }
        }

    }
}