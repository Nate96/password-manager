#include <iostream>
#include <ostream>
#include "StateMachine.h"
#include "HardwareAbstract.h"

using namespace std;

// REASERCH: Only expect 5 inputs for the password
// TODO: Use 6 as the enter key instead of enter.
void StateMachine::login() {
   int input;
   HardwareAbstract hal;

   cout << "Login:";
   input = hal.getInput();

   while ((input != hal.getPassword()) || (input > 99999)) {
      cout << "Please Try again." << endl;
      input = hal.getInput();
   }

   cout << "Welcome" << endl;
}

void updateSate(int input) {
   cout << "update state";
}
