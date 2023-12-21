#include <iostream>
#include "HardwareAbstract.h"

using namespace std;

int HardwareAbstract::getInput() {
   int input;
   cin >> input;
   return input;
}

int HardwareAbstract::getPassword() {
   return 12345;
}
