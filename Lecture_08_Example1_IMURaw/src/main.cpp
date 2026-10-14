#include <Arduino.h>
#include <BNO055_support.h>
#include <Wire.h>

struct bno055_t myBNO;
struct bno055_accel accel;
struct bno055_gyro gyro;
struct bno055_mag mag;

float ax = 0.0;
float ay = 0.0;
float az = 0.0;

float wx = 0.0;
float wy = 0.0;
float wz = 0.0;

float mx = 0.0;
float my = 0.0;
float mz = 0.0;

void setup() {

    Wire.begin();
    BNO_Init(&myBNO);
    bno055_set_operation_mode(OPERATION_MODE_NDOF);
    delay(10);

    Serial.begin(115200);
}

void loop() {

    bno055_read_accel_xyz(&accel);
    bno055_read_gyro_xyz(&gyro);
    bno055_read_mag_xyz(&mag);

    ax = float(accel.x) / 100;
    ay = float(accel.y) / 100;
    az = float(accel.z) / 100;

    wx = float(gyro.x) / 16;
    wy = float(gyro.y) / 16;
    wz = float(gyro.z) / 16;

    mx = float(mag.x) / 16;
    my = float(mag.y) / 16;
    mz = float(mag.z) / 16;

    Serial.print("a= ");
    Serial.print(ax);
    Serial.print(", ");
    Serial.print(ay);
    Serial.print(", ");
    Serial.println(az);

    Serial.print("w= ");
    Serial.print(wx);
    Serial.print(", ");
    Serial.print(wy);
    Serial.print(", ");
    Serial.println(wz);

    Serial.print("mag= ");
    Serial.print(mx);
    Serial.print(", ");
    Serial.print(my);
    Serial.print(", ");
    Serial.println(mz);

    Serial.println();

    delay(100);
}