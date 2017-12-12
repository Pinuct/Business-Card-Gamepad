#include <Joystick.h>
#include "TouchButtons.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  6, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

#define NUM_BUTTONS  10
                                    // start, select, a,  b,  x,  y,  up, left, down, right
const uint8_t buttons[NUM_BUTTONS] =    {A9,    A1,   A8, A7, A11, A6, A5, A3,   A2,   A4};

void setup() 
{
  // workarround for ADC A0
  pinMode(A0, INPUT_PULLUP);

  // No pins to setup, pins can still be used regularly, although it will affect readings
  TouchButtons_initButtons(buttons, NUM_BUTTONS);
  
  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
} 

void loop() 
{
  
  for(int i = 0; i < NUM_BUTTONS; i++){
    
    uint8_t currentButtonState = TouchButtons_getButtonsState(i);
    
    if (currentButtonState != 0){
      
      switch (i) {
        case 0: // START
          Joystick.setButton(0, currentButtonState==1?1:0);
          break;
        case 1: // SELECT
          Joystick.setButton(1, currentButtonState==1?1:0);
          break;
        case 2: // A
          Joystick.setButton(2, currentButtonState==1?1:0);
          break;
        case 3: // B
          Joystick.setButton(3, currentButtonState==1?1:0);
          break;
        case 4: // X
          Joystick.setButton(4, currentButtonState==1?1:0);
          break;
        case 5: // Y
          Joystick.setButton(5, currentButtonState==1?1:0);
          break;
        case 6: // UP
          if (currentButtonState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 7: // LEFT
          if (currentButtonState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 8: // DOWN
          if (currentButtonState == 1) {
            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 9: // RIGHT
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
      }
      
    }
    
  }

}
