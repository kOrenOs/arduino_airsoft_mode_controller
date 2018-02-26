#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Keypad.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

//keyboard row/column model
char keys[ROWS][COLS] =
 {{'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}};

//connect to the row pinouts of the keypad
byte rowPins[ROWS] = {6, 7, 8, 9}; 

// connect to the column pinouts of the keypad
byte colPins[COLS] = {10, 11, 12}; 

//keypad init
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
