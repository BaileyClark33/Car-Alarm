//=====[#include guards - begin]===============================================

#ifndef _IGNITION_H_
#define _IGNITION_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void ignitionStart();
void greenUpdate();
void ignitionFail();
void ignitionMain();

//=====[#include guards - end]=================================================

#endif // 

/*
Ignition Subsystem
When the driver sits down, display the message,
“Welcome to enhanced alarm system model 218-W25”.
Indicate ignition enabled with the green LED only when
both seats are occupied and both seatbelts are fastened.
 When the ignition button is pushed:
-        If the ignition enabled (green LED) is lit, then normal ignition
occurs. Light the blue LED and extinguish the green LED. Display the message,
“Engine started.”
-        If the ignition is not enabled (green LED not lit), then ignition is
inhibited. Sound the alarm buzzer; display the message, “Ignition inhibited” and
display all the reasons why the ignition was inhibited: “Passenger seat not
occupied,” “Driver seatbelt not fastened,” etc. Once the error messages are
displayed, the system allows additional start attempts. (note this change from
Project 1 requirements) Keep the engine running even if the driver or passenger
should remove their seat belts or exit the vehicle. When the engine is running,
stop the engine when the ignition button is pushed and then released. (note this
change from Project 1 requirements)
*\