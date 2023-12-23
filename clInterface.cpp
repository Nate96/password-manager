// GOAL: create new version with multiple file
// GOAL: Flash from mac to board
// Data Structure with all passwords. Make it easy to edit file on computer before flashing
// RESEARCH: Store data on the chip

/*
   Displays
   Login
   Passwords (Cycle through buttons)

   Functions
   Choose password
   Create password
   Enter in Pin to send password
   Enter in pin to login
   Enter in new login pin

   Buttons and pages layout
   Login Screen
   1   2
   3   4
   5   login

   Main
   Passwords | Edit Password
   Edit pins

   Passwords
   back   | next
   select | home

   Edit Passwords
   back   | next
   new    | delete
   select | home

   Select Passwrod
   1  2
   3  4
   5  enter

   Edit Pins
   login | Password

   Login -> Enter in old pin, enter in new pin -> change pin
   Password -> Enter in old pin, enter in new pin -> change pin
   */

// Hardware Abstract Layer (HAL)
// State Machine
// Password Generator

#include "StateMachine.h"
#include "HardwareAbstract.h"

using namespace std;

int main() {
   StateMachine sm;
   HardwareAbstract hal;

   int input;

   sm.login();

//   while (true) {
//      input = hal.getInput();
//      sm.updateSate(input);
//      
//   }
//
   return 0;
}
