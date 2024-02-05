/ GOAL: create new version with multiple file
// GOAL: Flash from mac to board
// RESEARCH: Store data on the chip

// Data Structure with all passwords. Make it easy to edit file on computer before flashing

// Hardware Abstract Layer (HAL)
// State Machine
// Password Generator

// RESEARCH: Built manage C projects
// TODO: Inplement Main state
// TODO: Flash current state to board
// TODO: Clean Repository


#include "src/StateMachine.h"

int main() {
  StateMachine sm;
  while(true) { sm.manage(); }
  return 0;
}
