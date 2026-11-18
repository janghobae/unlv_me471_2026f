#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

int contInput = 0;
int desPos = 0;
int currPos = 0;
float k_P = 0.1;
String command;

void setup() {
  controller.begin();
  Serial.begin(115200);
  Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0)
    {
        command = Serial.readString();
        command.trim();
        desPos = command.toInt();
    }
    
    currPos = encoder1.getRawCount();
    contInput = k_P * (desPos - currPos);

    if (contInput > 100)
    {
        contInput = 100;
    }
    else if (contInput < -100)
    {
        contInput = -100;
    }
    M1.setDuty(contInput);

    Serial.println(currPos);
    delay(10);
}
