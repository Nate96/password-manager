#include "StateMachine.h"

void StateMachine::manage() {
  char stateId = getState();
  State *state = new State();
  *state->run();
  delete state;
}
