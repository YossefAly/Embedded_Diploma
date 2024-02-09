#include "KEYPAD.h"

Int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns

void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init(){
		GPIO_INIT(KEYPAD_PORT,R0,OUTPUT_PUSHPULL);
		GPIO_INIT(KEYPAD_PORT,R1,OUTPUT_PUSHPULL);
		for(int i=3;i<9;i++){
			GPIO_INIT(KEYPAD_PORT,i,OUTPUT_PUSHPULL);
		}
		
		GPIO_WRITE_PORT(KEYPAD_PORT,0xFF);
}


char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {
		GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[0], HIGH);
		GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[1], HIGH);
		GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[2], HIGH);
		GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[3], HIGH);
		GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[i], LOW );
		for (j = 0; j < 4; j++) {
			if (GPIO_READ_PIN(KEYPAD_PORT, Key_padRow[j]) == 0) {
				while (GPIO_READ_PIN(KEYPAD_PORT, Key_padRow[j]) == 0)
					;
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
