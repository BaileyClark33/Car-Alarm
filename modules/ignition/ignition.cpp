//=====[Libraries]=============================================================

#include "ignition.h"
#include "alarm.h"
#include "mbed.h"
#include "arm_book_lib.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

DigitalOut engineLed(LED2); // NOT SURE IF NEEDED PUBLIC

//=====[Declaration and initialization of private global variables]============

DigitalIn driveSeatUsed(D4);
DigitalIn passSeatUsed(D5);
DigitalIn driveBelt(D6);
DigitalIn passBelt(D7);
DigitalIn ignitionButton(BUTTON1);

DigitalOut ignitionLed(LED1);

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

static bool welcomed = false;

//=====[Declarations (prototypes) of private functions]========================

void welcomeMessage();
void failMessage();
void engineStartMessage();
void engineStopMessage();
void checkCanIgnite();
void engineStart();
void engineStop();
void ignitionFail();

//=====[Implementations of public functions]===================================

void ignitionInit() {
    driveSeatUsed.mode(PullDown);
    passSeatUsed.mode(PullDown);
    driveBelt.mode(PullDown);
    passBelt.mode(PullDown);
    ignitionButton.mode(PullDown);
}

void ignitionUpdate() {
    if (!welcomed && driveSeatUsed == ON) {
        welcomeMessage();
        welcomed = true;
    }

    checkCanIgnite();

    if (ignitionButton == ON) {
        if (alarmRead()) {
            alarmDisable();
        }
        else if (ignitionLed == ON) {
            engineStart();
        }
        else if (engineLed == ON) {
            engineStop();
        }
        else {
            ignitionFail();
        }
    }
}

bool ignitionRead() {
    return engineLed == ON;
}

//=====[Implementations of private functions]==================================

void checkCanIgnite() {

    if (driveSeatUsed == ON && passSeatUsed == ON &&
        driveBelt == ON && passBelt == ON && engineLed == OFF) {
        ignitionLed = ON;
    } 
    else {
        ignitionLed = OFF;
    }
}

void engineStart() {
    engineLed = ON;
    ignitionLed = OFF;
    engineStartMessage();
}

void engineStop() {
    engineLed = OFF;
    engineStopMessage();
}

void ignitionFail() {
    alarmEnable();
    failMessage();
}

void welcomeMessage() {
    uartUsb.write("Welcome to enhanced alarm system model 218-W24\n", 47);
}

void engineStartMessage() {
    uartUsb.write("Engine Started\n", 16);
}

void engineStopMessage() {
    uartUsb.write("Engine Stopped\n", 16);
}

void failMessage() {
    uartUsb.write("Ignition inhibited\n", 20);

    if (driveSeatUsed == OFF) {
        uartUsb.write("Driver seat unoccupied\n", 24);
    }
    if (passSeatUsed == OFF) {
        uartUsb.write("Passenger seat unoccupied\n", 27);
    }
    if (driveBelt == OFF) {
        uartUsb.write("Driver seatbelt not fastened\n", 30);
    }
    if (passBelt == OFF) {
        uartUsb.write("Passenger seatbelt not fastened\n", 31);
    }
}