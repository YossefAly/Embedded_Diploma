#ifndef KEYPAD_H
#define KEYPAD_H

#include "GPIO_Interface.h"

#define KEYPAD_PORT IOB


#define R0 PIN0
#define R1 PIN1
#define R2 PIN3
#define R3 PIN4
#define C0 PIN5
#define C1 PIN6
#define C2 PIN7
#define C3 PIN8


void Keypad_init();
char Keypad_getkey();


#endif
