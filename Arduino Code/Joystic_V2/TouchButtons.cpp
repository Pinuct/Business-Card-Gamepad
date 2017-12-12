/*
 * 
 *    Touch button controller
 *    Maximun 12 buttons (12 ADC inputs)
 * 
 */
 
#include "TouchButtons.h"
#include "ADCTouch.h"

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

uint16_t touchButtonsRefs[MAX_BUTTONS] = {0};
uint8_t touchButtons[MAX_BUTTONS] = {0};
uint8_t touchButtonState[MAX_BUTTONS] = {0};
uint8_t numberOfTouchButtons = 0;

void TouchButtons_initButtons(uint8_t *Buttons, uint8_t NumberOfButtons){
  
  // 12 buttons max
  if(NumberOfButtons > MAX_BUTTONS){
    return;
  }

#if FASTADC
  // set prescale to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
#endif

  numberOfTouchButtons = NumberOfButtons;
  memcpy(touchButtons, Buttons, numberOfTouchButtons);

  // get initial references
  TouchButtons_getReferences();

  
}

void TouchButtons_getReferences(){
  for(int i = 0; i < numberOfTouchButtons; i++){
    touchButtonsRefs[i] = ADCTouch.read(touchButtons[i], 500);
  }
}

// button = button number from 0 to numberOfButtons - 1 
int TouchButtons_getButtonsState(uint8_t button){

  int result = 0;
  
  // if the button is not valid
  if(button >= numberOfTouchButtons){
    return false;
  }else{
    
    // retrun touchADC value - ADCRef compared to threshold
    int value = (int)(ADCTouch.read(touchButtons[button],SAMPLES_PER_BUTTON) - touchButtonsRefs[button]);
    bool currentSatate = value > (TOUCH_THRESHOLD - touchButtonState[button] * TOUCH_HYSTERESIS);

    if(touchButtonState[button] == currentSatate){
      result = 0;
    }else{
      if(currentSatate){
        result = 1;
      }else{
        result = -1;
      }
    }
    
    touchButtonState[button] = currentSatate;

    return result;
  }
  
}

