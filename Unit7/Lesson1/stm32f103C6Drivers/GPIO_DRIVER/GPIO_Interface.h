#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/***************************************INCLUDES**************************************/

#include "GPIO_Private.h"

/***************************************CONFIG***************************************/
//PORT

#define IOA		0
#define IOB		1
#define IOC		2
#define IOD		3

//PINS

enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
};

//MODE (This section specifies the mode of the pin)

enum{
	 INPUT_ANALOG,
	 INPUT_FLOATING,//INPUT
 	 INPUT_PULLUP,
 	 INPUT_PULLDOWN,
	 OUTPUT_PUSHPULL,
	 OUTPUT_OPENDRAIN,
	 AF_PUSHPULL,
	 AF_OPENDRAIN
};


//OUTPUT SPEED (This section specifies the speed of an output pin)

#define OUTPUT_LS	1   //2MHZ
#define OUTPUT_MS	2	//10MHZ
#define OUTPUT_HS	3	//50MHZ

//PIN STATE (This section specifies pin state)

#define HIGH 1
#define LOW 0

/*********************************************APIS**************************************/

void GPIO_INIT(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID,uint8_t Copy_u8PIN_MODE);
void GPIO_DEINIT(uint8_t Copy_u8PORT_ID);

uint16_t GPIO_READ_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID);
uint16_t GPIO_READ_PORT(uint8_t Copy_u8PORT_ID);

void GPIO_WRITE_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID,uint8_t Copy_u8value);
void GPIO_WRITE_PORT(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16value);

void GPIO_TOGGLE_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID);

void GPIO_LOCK_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID);

#endif
