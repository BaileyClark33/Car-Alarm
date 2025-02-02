# Driver's Ed Car System
### By Grady Bosanko and Bailey Clark

## System Summary
Our system is designed to improve the safety of driver's ed vehicles.
In order to start the car, the driver and passenger seats and seatbelts must
all be occupied. If any of these requirements are not met, an alarm will sound
and the user will see a message explaining why their ignition attempt failed.

Once the engine is running, the headlights of the car are enabled. We have
implemented a dial to switch the headlights between "ON", "OFF", and "AUTO".
The "AUTO" state uses a daylight sensor to turn the lights on during the night
and off during the day.

Finally, we implemented a high-beam switch. By toggling this switch, a second
set of lights will turn on whenever the headlights are turned on.

## Test Cases

| Specification | Test Result | Comment |
| ------------- | ----------- | ------- |
|Enable engine start (i.e., light the green LED) while both seats are occupied and seatbelts fastened. Otherwise print appropriate error message. | Pass | Appropriate error messages are printed. |
|Start the engine (i.e., light the blue LED, turn off Green) when ignition is enabled (green LED) and ignition button is pressed  (i.e., before the button is released). | Pass | |
| Keep the engine running even if the driver/passenger should unfasten belt and exit the vehicle. | Pass | |
| When the engine is running, stop the engine once the ignition button has been pushed and then released. | Pass | Engine shuts off as button is released consistently |
| User can attempt ignition again after a failed attempt. | Pass | Yes, pressing the ignition button while alarm is going off turns the alarm off and allows another attempt |
| Headlight selector "ON" state turns headlights on ONLY while engine is running | Pass | |
| Headlight selector "OFF" state turns headlights off regardless of engine status | Pass | |
| Headlight selector "AUTO" state turns headlights on depending on reading from daylight sensor| Pass | Covering the daylight sensor to simulate night turns the lights on as expected|
| Hibeam switch turns hibeams on ONLY when low beams are on | Pass | |