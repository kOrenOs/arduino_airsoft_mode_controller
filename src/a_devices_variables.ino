#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Keypad.h"

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte rows = 4; //four rows
const byte cols = 3; //three columns

// keyboard row/column model
char keys[rows][cols] =
 {{'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}};

// connect to the row pinouts of the keypad
byte row_pins[rows] = {12, 11, 10, 9}; 

// connect to the column pinouts of the keypad
byte col_pins[cols] = {8, 7, 6}; 

// keypad init
Keypad keypad = Keypad( makeKeymap(keys), row_pins, col_pins, rows, cols );

// active pin for speaker
int speaker_activate_pin = 48;

// buttons active pins
int first_bomb_button_pin = 52;
int second_bomb_button_pin = 50;
