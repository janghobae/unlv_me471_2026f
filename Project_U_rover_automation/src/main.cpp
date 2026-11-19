#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

int swPin = A6;
bool swVal = HIGH;
bool finished = false;

int drivePWM = 40;
int turnPWM = 35;
int M1Sign = 1;  // Left wheel
int M2Sign = 1;  // Right wheel

// Adjust these times on the rover. All times are in milliseconds.
int forwardTime = 1000;
int backTime = 1000;
int leftTime = 550;
int rightTime = 550;
int liftTime = 800;

// Keep the motor carrier active during each movement.
void waitMs(unsigned long duration) {
    unsigned long startTime = millis();
    while (millis() - startTime < duration)
    {
        controller.ping();
        delay(10);
    }
}

void stopWheels() {
    M1.setDuty(0);
    M2.setDuty(0);
    waitMs(100);
}

void setup() {
    pinMode(swPin, INPUT_PULLUP);
    if (!controller.begin())
    {
        while (true) { delay(100); }
    }
    stopWheels();
    servo1.setAngle(0);
}

void loop() {
    controller.ping();
    swVal = digitalRead(swPin);

    if (swVal == LOW && finished == false)
    {
        waitMs(30);
        swVal = digitalRead(swPin);
        if (swVal == HIGH)
        {
            return;
        }

        // 1. Move forward 30 cm
        M1.setDuty(M1Sign * drivePWM);
        M2.setDuty(M2Sign * drivePWM);
        waitMs(forwardTime);
        stopWheels();

        // 2. Turn left 90 degrees
        M1.setDuty(-M1Sign * turnPWM);
        M2.setDuty(M2Sign * turnPWM);
        waitMs(leftTime);
        stopWheels();

        // 3. Move forward 30 cm
        M1.setDuty(M1Sign * drivePWM);
        M2.setDuty(M2Sign * drivePWM);
        waitMs(forwardTime);
        stopWheels();

        // 4. Turn right 90 degrees
        M1.setDuty(M1Sign * turnPWM);
        M2.setDuty(-M2Sign * turnPWM);
        waitMs(rightTime);
        stopWheels();

        // 5. Move forward 30 cm
        M1.setDuty(M1Sign * drivePWM);
        M2.setDuty(M2Sign * drivePWM);
        waitMs(forwardTime);
        stopWheels();

        // 6. Lift the fork
        servo1.setAngle(90);
        waitMs(liftTime);

        // 7. Return to the origin: back up 30 cm
        M1.setDuty(-M1Sign * drivePWM);
        M2.setDuty(-M2Sign * drivePWM);
        waitMs(backTime);
        stopWheels();

        // Turn left 90 degrees
        M1.setDuty(-M1Sign * turnPWM);
        M2.setDuty(M2Sign * turnPWM);
        waitMs(leftTime);
        stopWheels();

        // Back up 30 cm
        M1.setDuty(-M1Sign * drivePWM);
        M2.setDuty(-M2Sign * drivePWM);
        waitMs(backTime);
        stopWheels();

        // Turn right 90 degrees
        M1.setDuty(M1Sign * turnPWM);
        M2.setDuty(-M2Sign * turnPWM);
        waitMs(rightTime);
        stopWheels();

        // Back up the final 30 cm
        M1.setDuty(-M1Sign * drivePWM);
        M2.setDuty(-M2Sign * drivePWM);
        waitMs(backTime);
        stopWheels();

        finished = true;
    }

    delay(10);
}
