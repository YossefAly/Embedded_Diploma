#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/******************************************INCLUDES************************************************/
#include <stdint.h>


/******************************************RCC BASE ADDRESSES*************************************/

#define RCC_BASE	0x40021000UL

/******************************************RCC PERIPHERALS****************************************/

typedef struct{

	volatile uint32_t    	   CR;
	volatile uint32_t    	 CFGR;
	volatile uint32_t     	  CIR;
	volatile uint32_t 	 APB2RSTR;
	volatile uint32_t 	 APB1RSTR;
	volatile uint32_t      AHBENR;
	volatile uint32_t  	  APB2ENR;
	volatile uint32_t  	  APB1ENR;
	volatile uint32_t     	 BDCR;

}RCC_TypeDef;

/*********************************************INSTANCES*******************************************/

#define RCC  ((volatile RCC_TypeDef*)RCC_BASE)


#endif
