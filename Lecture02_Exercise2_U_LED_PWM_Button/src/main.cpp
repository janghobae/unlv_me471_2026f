#include <Arduino.h>

int ledR = 19;
int sw = 18;
int intensity = 0;

void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(sw, INPUT);
    }

void loop() {
    if (digitalRead(sw) == LOW)
    {
        if (intensity < 255)
        {
            intensity += 5;
        }
    }
    else
    {
        if (intensity > 0)
        {
            intensity -= 5;
        }
    }

    analogWrite(ledR, intensity);
    delay(10);
}