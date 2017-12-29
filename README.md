[![License: CC BY 4.0](https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)

# Business-Card-Gamepad
Hardware and software files for the Business Card Gamepad.

**IF YOU WANT MORE DETAILS ABOUT THE PROJET  ----->  [HACKADAY.IO](https://hackaday.io/project/28516-business-card-gamepad) <-----**

It contains all necesary files to make a Business Card Gamepad. With capacitive touch buttons and USB interface thought a USB micro B PCB connector. If you connect it to a PC with a USB to micro USB cable, it acts as a joystick for the host PC.

# Folders

## Arduino Code

Contains the Arduino project for the gamepad code of the business card and a touch button library (used to detect capacitive button press). The code of the .ino is simple and self explanatory, it it initializes the joystick library and the touch buttons library and loops throught the readings of the touch buttons, when there is a press it send a joystick event to the PC.

If you want to compile this code you will need to include two more libraries. This code can't not work without the great libreries that Martin Pittermann ([ADCTouch library](https://github.com/martin2250/ADCTouch)) and Matthew Heironimus ([ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary)) did. So thanks to them to make this posible.

## Eagle PCB 

Contains an Eagle 7.50 project for the business card PCB. If you want to make it, is necesary to use a PCB of 0.6 mm thickness, needed for the USB PCB connector to be able to connect to a USB micro b cable.
