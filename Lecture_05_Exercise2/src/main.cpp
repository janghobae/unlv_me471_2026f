#include <Arduino.h>

int randInt = 0;

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(10);
}

void loop() {
    randInt = random(-100, 100);
    Serial.println(randInt);
    delay(100);
}