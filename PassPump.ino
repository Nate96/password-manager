// Create c++ interface
// GOAL: create new version with multiple file
// GOAL: Flash from mac to board
// Data Structure with all passwords. Make it easy to edit file on computer before flashing
// RESEARCH: Store data on the chip

/*
Displays
   Login
   Passwords (Cycle through buttons)

Functions
   Choose password
   Create password
   Enter in Pin to send password
   Enter in pin to login
   Enter in new login pin

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

// Abstract Layer
// State Machine
// Password Generator

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>

// OLED dementions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int button_1 = 10;
const int button_2 = 9;
const int button_3 = 8;

const int button_4 = 0;
const int button_5 = 1;
const int button_6 = 2;

int previousButtonState_1 = HIGH;
int previousButtonState_2 = HIGH;
int previousButtonState_3 = HIGH;
int previousButtonState_4 = HIGH;
int previousButtonState_5 = HIGH;
int previousButtonState_6 = HIGH;

void setup() {
  Serial.begin(57600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_4, INPUT_PULLUP);
  pinMode(button_5, INPUT_PULLUP);
  pinMode(button_6, INPUT_PULLUP);

  Keyboard.begin();

  displayLogin();
 
}

void loop() {
  //delay(5);
  //display.display(); 
}

void resetButtons(){
  previousButtonState_1 = HIGH;
  previousButtonState_2 = HIGH;
  previousButtonState_3 = HIGH;
  previousButtonState_4 = HIGH;
  previousButtonState_5 = HIGH;
  previousButtonState_6 = HIGH;
}

void displayLogin() {
  //login
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Login");

  display.setCursor(0,16);
  display.print(":");

  //display.setCursor(0,32);
  //display.print("Login");

  display.setCursor(0,48);
  display.print("Nolan INC");

  display.display();

  while(true)
  {
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_6 = buttonState_6;
    delay(5);
  }
}

void displayMain(){
  //main
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Main");


  display.setCursor(0,16);
  display.print("Pg 1  Pg 3");

  display.setCursor(0,32);
  display.print("Pg 2  Pg 4");

  display.setCursor(0,48);
  display.print("Exit  Pg 5");


  display.display();

  while(true)
  {
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;

    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayLogin();
      break;
    }
    previousButtonState_3 = buttonState_3;

    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      displayPg3();
      break;
    }
    previousButtonState_4 = buttonState_4;

    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;

    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    delay(5);
  }
}

void displayPg1(){
  //pg1
  resetButtons();
  delay(100);

  Serial.println("page 1");

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Pg-1 [1:9]");

  display.setCursor(0,16);
  display.print("Site 1");

  display.setCursor(0,32);
  display.print("Site 2");

  display.setCursor(0,48);
  display.print("Blank");

  display.display();

  while(true)
  {
    Serial.println("while loop start");
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      //displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      //displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;
    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_3 = buttonState_3;
    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      //displayMain();
      break;
    }
    previousButtonState_4 = buttonState_4;
    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      //displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      //displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    Serial.println("while loop end");
    delay(5);
  }
}

void displayPg2(){
  //pg2
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Pg-2 [1:9]");

  display.setCursor(0,16);
  display.print("Site 1");

  display.setCursor(0,32);
  display.print("Blank");

  display.setCursor(0,48);
  display.print("Blank");

  display.display();

  while(true)
  {
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      //displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      //displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;
    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_3 = buttonState_3;
    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      //displayMain();
      break;
    }
    previousButtonState_4 = buttonState_4;
    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      //displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      //displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    delay(5);
  }
}

void displayPg3(){
  //pg3
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Pg-3 [1:9]");

  display.setCursor(0,16);
  display.print("Site 1");

  display.setCursor(0,32);
  display.print("Site 2");

  display.setCursor(0,48);
  display.print("Site 3");

  display.display();

  while(true)
  {
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      //displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      //displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;
    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_3 = buttonState_3;
    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      //displayMain();
      break;
    }
    previousButtonState_4 = buttonState_4;
    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      //displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      //displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    delay(5);
  }
}

void displayPg4(){
  //pg4
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Pg-4 [1:9]");

  display.setCursor(0,16);
  display.print("Blank");

  display.setCursor(0,32);
  display.print("Blank");

  display.setCursor(0,48);
  display.print("Blank");

  display.display();

  
  while(true)
  {
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      //displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      //displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;
    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_3 = buttonState_3;
    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      //displayMain();
      break;
    }
    previousButtonState_4 = buttonState_4;
    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      //displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      //displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    delay(5);
  }
}

void displayPg5(){
  //pg5
  resetButtons();
  delay(100);

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(0,0);
  display.print("Pg-5 [1:9]");

  display.setCursor(0,16);
  display.print("Site 1");

  display.setCursor(0,32);
  display.print("Blank");

  display.setCursor(0,48);
  display.print("Blank");

  display.display();

  while(true)
  {
    int buttonState_1 = digitalRead(button_1);
    // if the button state has changed,
    if ((buttonState_1 != previousButtonState_1)
        // and it's currently pressed:
        && (buttonState_1 == HIGH)) {
      // type out a message
      //displayPg1();
      break;
    }
    previousButtonState_1 = buttonState_1;
    int buttonState_2 = digitalRead(button_2);
    // if the button state has changed,
    if ((buttonState_2 != previousButtonState_2)
        // and it's currently pressed:
        && (buttonState_2 == HIGH)) {
      // type out a message
      //displayPg2();
      break;
    }
    previousButtonState_2 = buttonState_2;
    int buttonState_3 = digitalRead(button_3);
    // if the button state has changed,
    if ((buttonState_3 != previousButtonState_3)
        // and it's currently pressed:
        && (buttonState_3 == HIGH)) {
      // type out a message
      displayMain();
      break;
    }
    previousButtonState_3 = buttonState_3;
    int buttonState_4 = digitalRead(button_4);
    // if the button state has changed,
    if ((buttonState_4 != previousButtonState_4)
        // and it's currently pressed:
        && (buttonState_4 == HIGH)) {
      // type out a message
      //displayMain();
      break;
    }
    previousButtonState_4 = buttonState_4;
    int buttonState_5 = digitalRead(button_5);
    // if the button state has changed,
    if ((buttonState_5 != previousButtonState_5)
        // and it's currently pressed:
        && (buttonState_5 == HIGH)) {
      // type out a message
      //displayPg4();
      break;
    }
    previousButtonState_5 = buttonState_5;
    int buttonState_6 = digitalRead(button_6);
    // if the button state has changed,
    if ((buttonState_6 != previousButtonState_6)
        // and it's currently pressed:
        && (buttonState_6 == HIGH)) {
      // type out a message
      //displayPg5();
      break;
    }
    previousButtonState_6 = buttonState_6;

    delay(5);
  }
}
