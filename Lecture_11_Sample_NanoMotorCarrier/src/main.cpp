#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

float batteryVoltage = 0.0;
int encoderCount = 0;

void setup() {
  controller.begin();
  Serial.begin(115200);

  M1.setDuty(0);
  M2.setDuty(0);
  M3.setDuty(0);
  M4.setDuty(0);
}

void loop() {
  //Take the battery status
  batteryVoltage = (float)battery.getRaw() / 77;
  encoderCount = encoder1.getRawCount();

  Serial.println(batteryVoltage);
  Serial.println(encoderCount);
  
  delay(100);
  
}