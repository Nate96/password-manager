#include "StateMachine.h"

StateMachine::StateMachine() { nextState = State::STATES::Login; }

void StateMachine::manage() {
  State *state; 

  switch(nextState) {
    case State::STATES::Login:
      // TODO: Implement LoginState
      LoginState login = new LoginState();
      state = login;
      break;
    case State::STATES::Main:
      // TODO: Implement MainStateState
      MainState main = new MainState();
      state = main;
      break; 
    case State::STATES::Select_Password:
      // TODO: Implement SelectPasswordState
      SelectPasswordSate sps = new SelectPassWordState();
      state = sps;
      break;
    case State::STATES::Edit_Password:
      // TODO: Implement EditPasswordStateState
      EditPasswordState eps = new EditPasswordState();
      state = eps;
      break;
    case State::STATES::Edit_Pin:
      // TODO: Implement EditPinState
      EditPinState eps = new EditPinState();
      state = eps;
      break;
    case State::STATES::Enter_Pin:
      // TODO: Implement EnterPinState
      EnterPinState eps = new EnterPinState();
      state = eps;
      break;
    default:
  }

  nextState = state->run();
  delete state;
}
