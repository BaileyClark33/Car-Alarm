//=====[Libraries]=============================================================

#include "mbed.h"
#include "headlights.h"
#include "arm_book_lib.h"
#include "daylight_sensor.h"
#include "ignition.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

typedef enum {
    LIGHTS_OFF,
    LIGHTS_AUTO,
    LIGHTS_ON
} selector_state_t_;

typedef enum {
    HIBEAM
    OFFBEAM
{ lamp_level_t_;

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

AnalogIn headlightSelect(A0);
DigitalOut leftLamp(D2);
DigitalOut rightLamp(D3);
DigitalOut leftHiBeam(D0);
DigitalOut rightHiBeam(D1);

DigitalIn hibeamSwitch(D1);

selector_state_t_ lightSelect;
lamp_level_t_ beamSelect;

//=====[Declarations (prototypes) of private functions]========================

void headlightsOff();
void headlightsOn();
void headlightsAuto();
void selectorUpdate();

//=====[Implementations of public functions]===================================

void headlightsUpdate() {
    selectorUpdate();
    if (!ignitionRead()) {
        lightSelect = LIGHTS_OFF;
    }
    switch(lightSelect) {
        case LIGHTS_OFF:
            headlightsOff();
            break;
        case LIGHTS_AUTO:
            headlightsAuto();
            break;
        case LIGHTS_ON:
            headlightsOn();
            break;
        default:
            lightSelect = LIGHTS_OFF;
    }
    switch(beamSelect) {
        case OFFBEAM:
            hibeamsOff();
            break;
        case HIBEAM:
            hibeamsOn();
            break;
        default:
            beamSelect = OFFBEAM;
    }
}

void headlightsInit() {
    lightSelect = LIGHTS_OFF;
    hibeamSelect = OFFBEAM;
    daylightSensorInit();
}

//=====[Implementations of private functions]==================================

void headlightsOff() {
    rightLamp = OFF; 
    leftLamp = OFF; 
}

void hibeamsOff() {
    lefthiBeam = OFF; 
    righthiBeam = OFF; 
}

void headlightsAuto() {
    bool daylight = readLightSensor();
    if (daylight) { 
        headlightsOff();
    } 
    else {
        headlightsOn();
    }
}

void headlightsOn() {
    if (ignitionRead()) {
        rightLamp = ON;
        leftLamp = ON;
    }
}

void hibeamsOn() {
    if (ignitionRead()) {
        lefthiBeam = ON; 
        righthiBeam = ON;
    }
}

void selectorUpdate() {
    float selectorVal = headlightSelect.read();
    if (selectorVal >= 0.8) {
        lightSelect = LIGHTS_ON;
    } 
    else if (0.2 < selectorVal && selectorVal < 0.8) {
        lightSelect = LIGHTS_AUTO;
    }
    else {
        lightSelect = LIGHTS_OFF;
  }

    if (hibeamSwitch == ON) {
        beamSelect = HIBEAM;
    } else {
        beamSelect = OFFBEAM;
    }
}
