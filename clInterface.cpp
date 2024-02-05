// GOAL: create new version with multiple file
// GOAL: Flash from mac to board

// RESEARCH: Store data on the chip
// RESEARCH: Building and Managing C++ files

// TODO: Inplement Main state
// TODO: Flash current state to board

// IDEA:Data Structure with all passwords. Make it easy to edit file on computer
// before flashing

#include "src/StateMachine.h"

int main() {
  StateMachine sm;
  while(true) { sm.manage(); }
  return 0;
}
