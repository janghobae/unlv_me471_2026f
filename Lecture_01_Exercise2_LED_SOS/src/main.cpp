#include <Arduino.h>

int ledPin = 13;   

// setup()
void setup() {     
    pinMode(ledPin, OUTPUT);
}

// loop()
void loop() {
    // S      
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);

    // letter space
    delay(300);

    // O
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);

    // letter space
    delay(300);

    // S
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100); // symbol space
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);

    // word space
    delay(700);
}