/*
 * STATES:
 *    Login
 *    Main
 *    Select Password
 *    Edit Passwords
 *    Edit Pins
 */
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "HardwareAbstract.h"

class StateMachine {
   public:
      void updateSate(int input);
      void login();
   private:
      void home();
      void passwords();
      void editPasword();
      void enterPin();
      void editPins();
};
#endif
