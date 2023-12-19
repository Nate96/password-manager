#include <iostream>
using namespace std;

#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5


int main() {
   cout << "Hello, world, from Visual C++!" << endl;
   int input;
   cin >> input;

   switch(input) {
      case BUTTON_1:
         cout << "You clicked 1" << endl;
         break;
   }
}
