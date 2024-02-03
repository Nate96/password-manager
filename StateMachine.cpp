#include "StateMachine.h"

void StateMachine::manage() {
  STATE stateId = getState();
  STATE *state = new State();
  *state->run();
  delete state;
}
