/*
 * STATES:
 *    Login
 *    Main
 *    Select Password
 *    Edit Passwords
 *    Edit Pins
 */

namespace PasswordManager {
   class state_machine {
      public:
         /*
         * Updates the state of the programe
         */
         void updateSate(int input);
         void login();
      private:

   };
}

