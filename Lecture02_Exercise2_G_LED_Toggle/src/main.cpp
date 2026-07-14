#include <Arduino.h>

int ledR = 16;
int ledG = 17;
int sw = 18;
int intensity = 0;
int color = true;
int intensity_R = 0;
int intensity_G = 0;

void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(sw, INPUT);
    }

void loop() {
    if (digitalRead(sw) == LOW)
    {
        if (color == true)
        {
            color = false;
        }
        else
        {
            color = true;
        }
    }

    if (color == true)
    {
        if (intensity_R < 255)
        {
            intensity_R += 5;
        }
        
        if (intensity_G > 0)
        {
            intensity_G -= 5;
        }
    }
    else
    {
        if (intensity_R > 0)
        {
            intensity_R -= 5;
        }
        
        if (intensity_G < 255)
        {
            intensity_G += 5;
        }
    }

    analogWrite(ledR, intensity_R);
    analogWrite(ledG, intensity_G);
    delay(50);
}