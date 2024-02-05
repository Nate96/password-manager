#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "HardwareAbstract.h"
#include "State.h"

class StateMachine {
  public:
    StateMachine();

    /**
     * Delete objects by using pointers and assigning the pointer to the new
     * state.
     * ENSURE: All created States are released from memory when done using 
     * pointers
     */
    void manage();

  private:
    State::STATES nextState;
   
    /**
     * Gets Current State from the Hardware Abstraction Layer
     * @return State object
     */
    State::STATES getState();
};
#endif
