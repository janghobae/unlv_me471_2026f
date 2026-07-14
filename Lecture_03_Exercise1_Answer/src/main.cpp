#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0) 
    {
        String message = Serial.readString();
        message.trim();
        Serial.print("Hello, ");
        Serial.println(message);
    }
}