#include <iostream>
#include "StateMachine.h"
#include "HardwareAbstract.h"

using namespace std;

void StateMachine::login() {
   int input;
   HardwareAbstract hal;

   cout << "Login:";
   input = hal.getInput();

   while ((input != hal.getPassword()) || (input > 99999)) {
      cout << "Please Try again." << endl;
      input = hal.getInput();
   }

   cout << "Welcome";
}

void updateSate(int input) {
   cout << "update state";
}
