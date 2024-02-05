
// REASERCH: Only expect 5 inputs for the password
// TODO: Use 6 as the enter key instead of enter.

/*
   Buttons and pages layout
   Login Screen
   1   2
   3   4
   5   login

   Main
   Passwords | Edit Password
   Edit pins

   Passwords
   back   | next
   select | home

   Edit Passwords
   back   | next
   new    | delete
   select | home

   Select Passwrod
   1  2
   3  4
   5  enter

   Edit Pins
   login | Password

   Login -> Enter in old pin, enter in new pin -> change pin
   Password -> Enter in old pin, enter in new pin -> change pin
 */

#include "HardwareAbstract.h"

class State {
  public:
    enum STATES {Login, Main, Select_Password, Edit_Password, Edit_Pin, Enter_Pin};
    /**
     * Runs the current state.
     * @Returns the next state enum
     */
    STATES run();

  private:
    HardwareAbstract hal;

    /** assigns proper functions to buttons for the current state. */
    void configbuttons();
    
    /** displays text for user */
    void writeScreen();

    /** determins new states based on user input and writes it to memory */
    void setNextState();
};
