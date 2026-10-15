#include <Arduino.h>
#include <BNO055_support.h>
#include <Wire.h>

struct bno055_t myBNO;
struct bno055_euler euler;

float roll = 0.0;
float pitch = 0.0;
float yaw = 0.0;

unsigned long lastTime = 0;

void setup() {
    Wire.begin();
    BNO_Init(&myBNO);
    bno055_set_operation_mode(OPERATION_MODE_NDOF);
    delay(10);
    Serial.begin(115200);
}

void loop() {
    bno055_read_euler_hrp(&euler);

    roll = float(euler.r) / 16.00;
    pitch = float(euler.p) / 16.00;
    yaw = float(euler.h) / 16.00;

    Serial.print("Roll: ");
    Serial.println(roll);

    Serial.print("Pitch: ");
    Serial.println(pitch);

    Serial.print("Yaw: ");
    Serial.println(yaw);
    Serial.println();

    delay(100);
}