#include <Arduino.h>

int xPin = A0;
int yPin = A1;
int swPin = 16;

int xVal = 0;
int yVal = 0;
int swVal = 0;

void setup() {
    Serial.begin(115200);

    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(swPin, INPUT_PULLUP);
}

void loop() {
    // put your main code here, to run repeatedly:
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    swVal = digitalRead(swPin);

    Serial.print("x: ");
    Serial.print(xVal);
    Serial.print(", ");
    Serial.print("y: ");
    Serial.print(yVal);
    Serial.print(", ");
    Serial.print("sw: ");
    Serial.println(swVal);

    delay(100);
}
