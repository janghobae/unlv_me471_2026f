#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 14

int ledPin = 19;
float temp = 0.0;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
    Serial.begin(115200);
    sensors.begin();
    pinMode(ledPin, OUTPUT);
}

void loop() {
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0);
    Serial.println(temp);

    if (temp > 30)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }

    delay(1000);
}
