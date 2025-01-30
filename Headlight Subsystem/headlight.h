//=====[#include guards - begin]===============================================

#ifndef _HEADLIGHT_H_
#define _HEADLIGHT_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void headlightsOff();
void ignitionRun();

//=====[#include guards - end]=================================================

#endif // 

/*
Headlight subsystem
If the engine is running, and the user selects: ON, turn on both low beam lamps;
if they select OFF, turn off all lamps.
If the user selects the AUTO position:
When the light level is above a “daylight” level, switch headlights off after
a delay of 2 seconds.
When the light level is below a “dusk” level, switch headlights on after a delay
of 1 second. When between these two levels, the headlights should hold their
previous state. Turn off all headlights when the engine is off.
*/