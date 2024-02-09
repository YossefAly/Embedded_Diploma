#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/******************************************INCLUDES************************************************/
#include <stdint.h>

#include "RCC_Private.h"

/******************************************GPIO BASE ADDRESSES*************************************/

#define EXTI_BASE	0x40010400UL


/******************************************GPIO PERIPHERALS***************************************/

typedef struct{

	volatile uint32_t      IMR;
	volatile uint32_t      EMR;
	volatile uint32_t  	  RTSR;
	volatile uint32_t  	  FTSR;
	volatile uint32_t 	 SWIER;
	volatile uint32_t    	PR;

}EXTI_TypeDef;

/*********************************************INSTANCES*******************************************/

#define EXTI volatile (EXTI_TypeDef*)(EXTI_BASE);



#endif
