#include "LoginState.h"

void State::run() { 
  HardwareAbstract hal; 
  STATES currentState = STATES::Login;
  configbuttons();
  writeScreen();
  int input = hal.getInput();
  
  //do things
  // ..
  // ..
  
  hal.setNextState(nextState);
}
