#include <Arduino.h>

#define SERIESRESISTOR 10000
#define NOMINAL_RESISTANCE 10000
#define NOMINAL_TEMPERATURE 25
#define BCOEFFICIENT 3950

float tempCal(float);

int tempSensorPin = A0;
float tempRaw = 0;

void setup() {
    pinMode(tempSensorPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    tempRaw = analogRead(tempSensorPin);
    // Serial.println(tempRaw);
    Serial.println(tempCal(tempRaw));
}

float tempCal(float SensorValue) {

    float Resistance = 0;
    float temperature = 0;

    Resistance = (1023 / SensorValue) - 1;
    Resistance = SERIESRESISTOR / Resistance;

    temperature = Resistance / NOMINAL_RESISTANCE;
    temperature = log(temperature); // ln(R/Ro)
    temperature /= BCOEFFICIENT; // 1/B * ln(R/Ro)
    temperature += 1.0 / (NOMINAL_TEMPERATURE + 273.15); // + (1/To)
    temperature = 1.0 / temperature; // Invert
    temperature -= 273.15; // convert to C

    return temperature;
}