// TODO: Read and Right to File type

#ifndef HARDWARE_ABSTRACT_H
#define HARDWARE_ABSTRACT_H

#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5
#define BUTTON_6 6

class HardwareAbstract {
   public:
      int getInput();
      int getPassword();
   private:

};
#endif
