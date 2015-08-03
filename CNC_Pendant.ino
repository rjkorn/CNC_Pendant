//****************************************************************
//*  Name    : CNC Pendant using Leonardo                        *
//*  Author  : Robert Joseph Korn                                *
//*  Notice  : Copyright (c) 2015 Open Valley Consulting Corp    *
//*          : All Rights Reserved                               *
//*  Date    : 5/29/15                                           *
//*  Version : 1.0                                               *
//*  Notes   :                                                   *
//*          :                                                   *
//****************************************************************

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
    Keyboard.begin();
    keypad.setHoldTime(250);
    keypad.setDebounceTime(25);
    keypad.addEventListener(keypadEvent); 
}

void loop(){
    char key = keypad.getKey();
    delay(100);
}

void keypadEvent(KeypadEvent key){
  
    switch (key){
 
    case '2':
      key = 0xDA;
      break;

    case '3':
      key = 0xD3;
      break;

    case '4':
      key = 0xD8;
      break;

    case '6':
      key = 0xD7;
      break;

    case '8':
      key = 0xD9;
      break;

    case '9':
      key = 0xD6;
      break;
  
    }
    
    switch (keypad.getState()){
    case PRESSED:
        Keyboard.press(key);
        break;

    case RELEASED:
        Keyboard.releaseAll();
        break;

    case HOLD:
        break;
    }
}
