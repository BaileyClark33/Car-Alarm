//=====[Libraries]=============================================================

#include "mbed.h"
#include "headlights.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

#define DAYLIGHT_THRESHOLD 0.6 // REPLACE IN MODULE

//=====[Declaration of private data types]=====================================

AnalogIn headlightSelect(A0); // REPLACE WITH MODULE
AnalogIn lightSensor(A1); // REPLACE WITH MODULE
DigitalOut leftLamp(D2);
DigitalOut rightLamp(D3);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void headlightsOff();

//=====[Implementations of public functions]===================================

void headlightsUpdate() { // FIX AFTER OTHER MODULES
  if (headlightSelect >= 0.8) {
    rightLamp = ON;
    leftLamp = ON;
  } 
  else if (headlightSelect > 0.2 && headlightSelect < 0.8) {
    if (lightSensor >= DAYLIGHT_THRESHOLD) { 
      rightLamp = OFF;
      leftLamp = OFF;
    } 
    else {
      rightLamp = ON;
      leftLamp = ON;
    }
  }
  else {
    rightLamp = OFF;    
    leftLamp = OFF;
  }
}

//=====[Implementations of private functions]==================================

void headlightsOff() {
    rightLamp = OFF; 
    leftLamp = OFF; 
}