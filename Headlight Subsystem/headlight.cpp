//=====[Libraries]=============================================================

#include "mbed.h"
#include "headlight.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

// Headlight mode selector (provides ON, OFF, or AUTO signals);
// Light sensor (provides ambient light level signal);
// Left low beam lamp, right low beam lamp
DigitalIn headlightSelect();
DigitalIn lightSensor();
DigitalIn leftLamp();
DigitalIn rightLamp();

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void headlightsOff() {
    rightLamp == OFF; 
    leftLamp == OFF; 
}

void ignitionRun() {
  // If the engine is running, and the user selects: ON, turn on both low beam
  // lamps;
  if (headlightSelect == ON) {
    rightLamp == ON;
     leftLamp == ON;
  } else if (headlightSelect ==
             OFF) { // if they select OFF, turn off all lamps.
    rightLamp == OFF; leftLamp == OFF;
  } else if (headlightSelect ==
             AUTO) { // If the user selects the AUTO position:
    if (lightSensor >=
        daylightMin) { // When the light level is above a “daylight” level,
      // switch headlights off after a delay of 2 seconds.
      delay(2000);
      rightLamp == OFF;
      leftLamp == OFF;
    } else if (lightSensor <=
               duskMax) { // When the light level is below a “dusk” level,
      // switch headlights on after a delay of 1 second.
      delay(1000);
      rightLamp == ON leftLamp == ON
      // When between these two levels, the headlights should hold their
      // previous state.
    }
  }
}

//=====[Implementations of private functions]==================================

