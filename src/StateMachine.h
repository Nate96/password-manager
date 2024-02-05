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
<<<<<<< HEAD:src/StateMachine.h
    State::STATES nextState;
=======
    HardwareAbstract hal;
   
    /**
     * Gets Current State from the Hardware Abstraction Layer
     * @return State object
     */
    State::STATES getState();
>>>>>>> b213d5bb4f1eb0996e9d8e69daccc23b9cf0de8a:StateMachine.h
};
#endif
