//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "mbed.h"
#include "daylight_sensor.h"

//=====[Declaration of private defines]========================================

#define NUMBER_OF_SAMPLES 10
#define THRESHOLD 0.6

//=====[Declaration and initialization of private global variables]============

bool lightSensorState;
float lightSensorReadings[NUMBER_OF_SAMPLES];
AnalogIn LDR(A1);

//=====[Implementations of public functions]===================================

void daylightSensorInit() {
  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    lightSensorReadings[i] = 0.0;
  }
  lightSensorState = OFF;
}

void daylightSensorUpdate() {
    // Averages multiple readings to increase consistency
  static int sensorReadingIndex = 0;
  float readingSum = 0;
  float readingAvg = 0;
  lightSensorReadings[sensorReadingIndex] = LDR.read();
  sensorReadingIndex = (sensorReadingIndex + 1) % NUMBER_OF_SAMPLES;

  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    readingSum += lightSensorReadings[i];
  }
  readingAvg = readingSum / NUMBER_OF_SAMPLES;
  lightSensorState = readingAvg > THRESHOLD;
}

bool readLightSensor() { return lightSensorState; }