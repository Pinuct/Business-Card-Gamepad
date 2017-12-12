/*
 * 
 *    Touch button controller
 *    Maximun 12 buttons (12 ADC inputs)
 * 
 */

#ifndef TOUCHBUTTONS_H
#define TOUCHBUTTONS_H

#include <Arduino.h>
 
#define MAX_BUTTONS                 12
#define TOUCH_THRESHOLD             30      // the limit value for considering a button press
#define TOUCH_HYSTERESIS            20      // hysteresis for reducing noise button presses
#define SAMPLES_PER_BUTTON          100     // the more samples the more accurate the measure


// 1 to fast ADC conversion, 0 to normal Arduino ADC conversion time
#define FASTADC 1


void TouchButtons_initButtons(uint8_t *buttons, uint8_t numberOfButtons);
void TouchButtons_getReferences();
int TouchButtons_readADCTouch(byte ADCChannel, int samples);
int TouchButtons_getButtonsState(uint8_t button);

#endif
