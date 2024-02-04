#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "HardwareAbstract.h"
#include "State.h"

class StateMachine {
  public:
    /**
     * Delete objects by using pointers and assigning the pointer to the new
     * state.
     * ENSURE: All created States are released from memory when done using 
     * pointers
     */
    void manage();

  private:
    HardwareAbstract hal;
   
    /**
     * Gets Current State from the Hardware Abstraction Layer
     * @return State object
     */
    STATE getState();
};
#endif
