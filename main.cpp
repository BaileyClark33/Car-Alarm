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


  //  When the driver sits down, display the message, “Welcome to enhanced
  //  alarm system model 218-W24”.
  while (driveSeatUsed == OFF) {
  }


  system.write("Welcome to enhanced alarm system model 218-W24\n", 47);
  // Light the green LED only when both seats are occupied and both
  // seatbelts are fastened.
  // system.write("test\n", 6);


  while (ignition == OFF) {
    if (driveSeatUsed == ON && passSeatUsed == ON && driveBelt == ON &&
        passBelt == ON) {
      green = ON;
    } else {
      green = OFF;
    }
  }
  //  When the ignition button is pushed:


  // The user only gets one try to press the ignition button, and if the alarm
  // sounds, or the car starts, then the system must be reset.


  if (green == ON) {
    // -        If the green LED is lit, then normal ignition occurs.
    //          Light the blue LED and extinguish the green LED. Display
    //          the message, “Engine started.”
    blue = ON;
    green = OFF;
    system.write("Engine Started\n", 16);


   
  } else {
      // -        If the green LED is not lit, then ignition is inhibited.
    // Sound the alarm buzzer;
    alarm.output();
    //          display the message, “Ignition inhibited” and


    //     display all
    //          the reasons why the ignition was inhibited: “Passenger
    //          seat not occupied,” “Driver seatbelt not fastened,” etc.
    system.write("Ignition inhibited\n", 20);


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
}

