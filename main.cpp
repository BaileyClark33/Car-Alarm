#include "arm_book_lib.h"
#include "mbed.h"

/* According to a provision of the New York State Department of Motor Vehicles:
“If you have a junior learner permit, you may drive in upstate New York between
the hours of 5 AM and 9 PM only under the direct supervision of a person who is
at least age 21 and has a license valid for the vehicle you are driving.” Some
New York public high schools are looking to upgrade the car alarm software in
their Driver’s Education vehicles to help enforce this provision and also to
enhance driver and passenger safety.
*/
int main() {
  // Driver seat occupancy sensor (provides contact closure when occupied);
  // Passenger seat occupancy sensor (provides contact closure when occupied);
  // Driver seatbelt sensor (provides contact closure when fastened);
  // Passenger seatbelt sensor (provides contact closure when fastened);
  // Ignition push button (provides contact closure to request ignition);
  DigitalIn driveSeatUsed(D1);
  DigitalIn passSeatUsed(D2);
  DigitalIn driveBelt(D3);
  DigitalIn passBelt(D4);
  DigitalIn ignition(D5);

  // Alarm buzzer (sounds when ignition is inhibited);
  // Green indicator LED (lights when ignition is enabled);
  //  Blue indicator LED (lights when the engine has started);
  DigitalInOut alarm(P10);
  DigitalOut green(LED2);
  DigitalOut blue(LED3);

  driveSeatUsed.mode(PullDown);
  passSeatUsed.mode(PullDown);
  driveBelt.mode(PullDown);
  passBelt.mode(PullDown);
  ignition.mode(PullDown);

  // The user only gets one try to press the ignition button, and if the alarm
  // sounds, or the car starts, then the system must be reset.
  //          Hence no while true loop

  while
    true {

      //  When the driver sits down, display the message, “Welcome to enhanced
      //  alarm system model 218-W24”.
      if driveSeatUsed
        == ON { print("Welcome to enhanced alarm system model 218-W24"); }

      // Light the green LED only when both seats are occupied and both
      // seatbelts are fastened.
      if driveSeatUsed
        == ON &&passSeatUsed == ON &&driveBelt == ON &&passBelt == ON {
          green == ON;
        }

      //  When the ignition button is pushed:
      true if ignition == ON {
        if green
          == ON {
            // -        If the green LED is lit, then normal ignition occurs.
            //          Light the blue LED and extinguish the green LED. Display
            //          the message, “Engine started.”
            blue == ON;
            green == OFF;
            print("Engine Started");
          }
        else {
          // -        If the green LED is not lit, then ignition is inhibited.
          // Sound the alarm buzzer;
          //          display the message, “Ignition inhibited” and display all
          //          the reasons why the ignition was inhibited: “Passenger
          //          seat not occupied,” “Driver seatbelt not fastened,” etc.
          alarm == ON print("Ignition inhibited");

          if driveSeatUsed
            == OFF { print("Driver seat unoccupied") }

          if passSeatUsed
            == OFF { print("Passenger seat unoccupied") }

          if driveBelt
            == OFF { print("Driver seatbelt not fastened") }

          if passBelt
            == OFF { print("Passenger seatbelt not fastened") }
        }
      }
      else if {
        while
          true {}
      }
    }
}
