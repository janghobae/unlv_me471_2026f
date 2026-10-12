#include <Arduino.h>

int xPin = A0;
int yPin = A1;
int swPin = 19;

int xVal = 0;
int yVal = 0;
int swVal = 0;

void setup() {
    Serial.begin(115200);
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(swPin, INPUT);
}

void loop() {
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    swVal = digitalRead(swPin);
    Serial.println(xVal);
    Serial.println(yVal);
    Serial.println(swVal);

    delay(100);
}
