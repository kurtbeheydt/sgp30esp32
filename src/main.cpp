#include <Wire.h>

#include "SparkFun_SGP30_Arduino_Library.h"

/*
* SDA : port 21
* SCL : port 22
*
*/


SGP30 mySensor;  //create an object of the SGP30 class

void setup() {
    Serial.begin(115200);
    Wire.begin();
    if (mySensor.begin() == false) {
        Serial.println("No SGP30 Detected. Check connections.");
        while (1)
            ;
    }
    mySensor.initAirQuality();
}

void loop() {
    //First fifteen readings will be
    //CO2: 400 ppm  TVOC: 0 ppb
    delay(1000);  //Wait 1 second
    //measure CO2 and TVOC levels
    mySensor.measureAirQuality();
    Serial.print("CO2: ");
    Serial.print(mySensor.CO2);
    Serial.print(" ppm\tTVOC: ");
    Serial.print(mySensor.TVOC);
    Serial.println(" ppb");
}