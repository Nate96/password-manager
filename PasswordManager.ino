#include "src/StateMachine.h"

StateMachine sm;

void setup() {
  sm = new StateMachine();
}

void loop() {
  sm.manage();
}

