#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5
#define BUTTON_6 6

namespace PasswordManager {

   class hardware_abstract {

      /*
       * Get input from the hardware
       */
      public:
         int getInput();
      private:

   };
}
