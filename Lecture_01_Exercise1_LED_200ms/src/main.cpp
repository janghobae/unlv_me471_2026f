#include <Arduino.h>

int ledPin = 13;   

// setup()
void setup() {     
  pinMode(ledPin, OUTPUT);
}

// loop()
void loop() {      
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}