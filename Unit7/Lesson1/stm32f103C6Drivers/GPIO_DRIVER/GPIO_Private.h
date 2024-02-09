#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/******************************************INCLUDES************************************************/

#include "RCC_Private.h"

/******************************************GPIO BASE ADDRESSES*************************************/

#define GPIOA_BASE	0x40010800UL
#define GPIOB_BASE	0x40010C00UL
#define GPIOC_BASE	0x40011000UL
#define GPIOD_BASE	0x40011400UL


/******************************************GPIO PERIPHERALS***************************************/

typedef struct{

	volatile uint32_t  CRL;
	volatile uint32_t  CRH;
	volatile uint32_t  IDR;
	volatile uint32_t  ODR;
	volatile uint32_t BSRR;
	volatile uint32_t  BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef;

/*********************************************INSTANCES*******************************************/

#define GPIOA 	 ((volatile GPIO_TypeDef	*)GPIOA_BASE)
#define GPIOB 	 ((volatile GPIO_TypeDef	*)GPIOB_BASE)
#define GPIOC 	 ((volatile GPIO_TypeDef	*)GPIOC_BASE)
#define GPIOD 	 ((volatile GPIO_TypeDef	*)GPIOD_BASE)


/*****************************************CLOCK ENABLE MACROS************************************/

#define GPIOA_CLK_ENABLE()	(RCC->APB2ENR |= 1<<2)
#define GPIOB_CLK_ENABLE()	(RCC->APB2ENR |= 1<<3)
#define GPIOC_CLK_ENABLE()	(RCC->APB2ENR |= 1<<4)
#define GPIOD_CLK_ENABLE()	(RCC->APB2ENR |= 1<<5)

#endif
