#include <Arduino.h>
#include <BNO055_support.h>
#include <Wire.h>

struct bno055_t myBNO;
struct bno055_gyro gyro;

float wx = 0.0;
float wy = 0.0;
float wz = 0.0;

float roll = 0.0;
float pitch = 0.0;
float yaw = 0.0;

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
        bno055_read_gyro_xyz(&gyro);

        wx = float(gyro.x) / 16;
        wy = float(gyro.y) / 16;
        wz = float(gyro.z) / 16;

        roll = roll + wy * dt / 1000;
        pitch = pitch + wx * dt / 1000;
        yaw = yaw + wz * dt / 1000;

        Serial.print("roll= ");
        Serial.print(roll);
        Serial.print(", ");
        Serial.print("pitch= ");
        Serial.print(pitch);
        Serial.print(", ");
        Serial.print("yaw= ");
        Serial.println(yaw);
    }
}