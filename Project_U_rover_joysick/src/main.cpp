#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

int xPin = A2;
int yPin = A3;
int swPin = A6;

int xVal = 0;
int yVal = 0;
bool swVal = 0;

int M1PWM = 0;
int M2PWM = 0;
bool liftStat = 0;

void setup() {
    controller.begin();
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(swPin, INPUT);
}

void loop() {

    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    swVal = digitalRead(swPin);

    M1PWM = (xVal - 512) / 1024 * 100 + (yVal - 512) / 1024 * 100;
    M2PWM = (xVal - 512) / 1024 * 100 - (yVal - 512) / 1024 * 100;

    M1.setDuty(M1PWM);
    M2.setDuty(M2PWM);

    if (swPin == 1)
    {
        if (liftStat == 0)
        {
            liftStat = 1;
        }
        else
        {
            liftStat = 0;
        }
    }

    if (liftStat == 0)
    {
        servo1.setAngle(0);
    }
    else
    {
        servo1.setAngle(90);
    }

    delay(10);
}
