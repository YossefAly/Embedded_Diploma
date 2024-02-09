#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


/******************************************INCLUDES************************************************/
#include <stdint.h>

#include "RCC_Private.h"

/******************************************GPIO BASE ADDRESSES*************************************/

#define AFIO_BASE	0x0x40010000 UL


/******************************************GPIO PERIPHERALS***************************************/

typedef struct{

	volatile uint32_t         EVCR;
	volatile uint32_t         MAPR;
	volatile uint32_t  	   EXTICR1;
	volatile uint32_t  	   EXTICR2;
	volatile uint32_t 	   EXTICR3;
	volatile uint32_t      EXTICR4;
	uint32_t    		  RESERVED;
	volatile uint32_t        MAPR2;

}AFIO_TypeDef;

/*********************************************INSTANCES*******************************************/

#define AFIO volatile (AFIO_TypeDef*)(AFIO_BASE);

/*****************************************CLOCK ENABLE MACROS************************************/

#define AFIO_CLK_ENABLE()	(RCC->APB2ENR |= 1<<0)

#endif
