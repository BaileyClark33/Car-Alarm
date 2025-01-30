//=====[Libraries]=============================================================

#include "ignition.h"
#include "headlight.h"
#include "mbed.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

// Driver seat occupancy sensor (provides contact closure when occupied);
// Passenger seat occupancy sensor (provides contact closure when occupied);
// Driver seatbelt sensor (provides contact closure when fastened);
// Passenger seatbelt sensor (provides contact closure when fastened);
// Ignition push button (provides contact closure to request ignition);
DigitalIn driveSeatUsed(D1);
DigitalIn passSeatUsed(D2);
DigitalIn driveBelt(D6);
DigitalIn passBelt(D7);
DigitalIn ignition(D5);
// Alarm buzzer (sounds when ignition is inhibited);
// Green indicator LED (lights when ignition is enabled);
//  Blue indicator LED (lights when the engine has started);
DigitalInOut alarm(PE_10);
DigitalOut green(LED1);
DigitalOut blue(LED2);

driveSeatUsed.mode(PullDown);
passSeatUsed.mode(PullDown);
driveBelt.mode(PullDown);
passBelt.mode(PullDown);
ignition.mode(PullDown);

UnbufferedSerial system(USBTX, USBRX, 115200);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void ignitionMain() {
  //   When the driver sits down, display the message,
  // “Welcome to enhanced alarm system model 218-W25”.
  while (driveSeatUsed == OFF) {
  }
  system.write("Welcome to enhanced alarm system model 218-W24\n", 47);
  // Indicate ignition enabled with the green LED only when
  // both seats are occupied and both seatbelts are fastened
  while (ignition == OFF) {
    greenUpdate()
  }
  //  When the ignition button is pushed:
  // -        If the ignition enabled (green LED) is lit, then normal ignition
  // occurs. Light the blue LED and extinguish the green LED. Display the
  // message, “Engine started.”
  if (green == ON) {
    ignitionStart()
    // -        If the ignition is not enabled (green LED not lit), then
    // ignition is inhibited. Sound the alarm buzzer; display the message,
    // “Ignition inhibited” and display all the reasons why the ignition was
    // inhibited: “Passenger seat not occupied,” “Driver seatbelt not
    // fastened,” etc.
  } else {
    ignitionFail()
  }
}

void greenUpdate() {
  // Light the green LED only when both seats are occupied and both
  // seatbelts are fastened.
  if (driveSeatUsed == ON && passSeatUsed == ON && driveBelt == ON &&
      passBelt == ON) {
    green = ON;
  } else {
    green = OFF;
  }
}

void ignitionStart() {
  // -        If the green LED is lit, then normal ignition occurs.
  //          Light the blue LED and extinguish the green LED. Display
  //          the message, “Engine started.”
  blue = ON;
  green = OFF;
  system.write("Engine Started\n", 16);

  while (ignition == false) {
    ignitionRun()
  }
  // Keep the engine running even if the driver or passenger should remove their
  // seat
  // belts or exit the vehicle.
  while (ignition == true) {
  }
  // When the engine is running, stop the engine when the ignition button is
  // pushed and then released. (note this change from Project 1 requirements)
  // Turn off all headlights when the engine is off.
  headlightsOff();
  blue = OFF;
  green = OFF;
  system.write("Engine Stopped\n", 16);
}

void ignitionFail() {
  // -        If the green LED is not lit, then ignition is inhibited.
  // Sound the alarm buzzer;
  alarm.output();
  //          display the message, “Ignition inhibited” and
  system.write("Ignition inhibited\n", 20);
  //     display all
  //          the reasons why the ignition was inhibited: “Passenger
  //          seat not occupied,” “Driver seatbelt not fastened,” etc.
  if (driveSeatUsed == OFF) {
    system.write("Driver seat unoccupied\n", 24);
  }
  if (passSeatUsed == OFF) {
    system.write("Passenger seat unoccupied\n", 27);
  }
  if (driveBelt == OFF) {
    system.write("Driver seatbelt not fastened\n", 30);
  }
  if (passBelt == OFF) {
    system.write("Passenger seatbelt not fastened\n", 31);
  }
}

//=====[Implementations of private functions]==================================
