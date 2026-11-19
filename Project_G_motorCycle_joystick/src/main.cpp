#include <Arduino.h>
#include <ArduinoMotorCarrier.h>
#include <BNO055_support.h>
#include <Wire.h>

int xPin = A2;
int yPin = A3;

int xVal = 0;
int yVal = 0;

int M1PWM = 0;
int M2PWM = 0;

struct bno055_t myBNO;
struct bno055_euler euler;
struct bno055_gyro gyro;

float roll = 0.0;
float pitch = 0.0;
float yaw = 0.0;

float wx = 0.0;
float wy = 0.0;
float wz = 0.0;

float k_P = 0.1;
float k_I = 0.01;
float k_D = 0.01;

void setup() {
    controller.begin();
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);

    Wire.begin();
    BNO_Init(&myBNO);
    bno055_set_operation_mode(OPERATION_MODE_NDOF);
    delay(10);
}

void loop() {
    bno055_read_euler_hrp(&euler);
    bno055_read_gyro_xyz(&gyro);

    wx = float(gyro.x) / 16;
    wy = float(gyro.y) / 16;
    wz = float(gyro.z) / 16;

    roll = float(euler.r) / 16.00;
    pitch = float(euler.p) / 16.00;
    yaw = float(euler.h) / 16.00;

    xVal = analogRead(xPin);
    yVal = analogRead(yPin);

    M1PWM = (xVal - 512) / 1024;
    M1.setDuty(M1PWM);

    servo1.setAngle(yVal / 1024 * 360);

    M2PWM = k_P * roll + k_D * wy + k_I * roll * 0.01;

    delay(10);
}
