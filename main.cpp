#include "arm_book_lib.h"
#include "ignition.h"
#include "headlight.h"
#include "mbed.h"
#define daylightMin 0.6
#define duskMax 0.5

int main() {
  // Once the error messages are displayed, the system allows additional start
  // attempts. (note this change from Project 1 requirements)
  while (true) {
    ignitionMain();
  }
}
