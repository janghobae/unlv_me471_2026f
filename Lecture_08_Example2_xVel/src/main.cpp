#include <Arduino.h>
#include <BNO055_support.h>
#include <Wire.h>

struct bno055_t myBNO;
struct bno055_accel accel;

float ax = 0.0;
float vx = 0.0;

unsigned int dt = 10;
unsigned long prevTime = 0;

void setup() {
    Wire.begin();
    BNO_Init(&myBNO);
    bno055_set_operation_mode(OPERATION_MODE_NDOF);
    delay(10);
    Serial.begin(115200);
}

void loop() {
    if ((millis() -  prevTime) >= dt)
    {
        prevTime = millis();
        bno055_read_accel_xyz(&accel);

        ax = float(accel.x) / 100;
        vx = vx + ax * dt / 1000;

        Serial.print("vx= ");
        Serial.println(vx);
    }
}