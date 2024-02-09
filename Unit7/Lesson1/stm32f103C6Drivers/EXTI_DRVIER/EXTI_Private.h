#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/******************************************INCLUDES************************************************/
#include <stdint.h>



/******************************************EXTI BASE ADDRESSES*************************************/

#define EXTI_BASE	0x40010400UL


/******************************************EXTI PERIPHERALS***************************************/

typedef struct{

	volatile uint32_t      IMR;
	volatile uint32_t      EMR;
	volatile uint32_t  	  RTSR;
	volatile uint32_t  	  FTSR;
	volatile uint32_t 	 SWIER;
	volatile uint32_t    	PR;

}EXTI_TypeDef;

/*********************************************INSTANCES*******************************************/

#define EXTI ((volatile EXTI_TypeDef*)EXTI_BASE)

/****************************************NVIC ENABLE MACROS***************************************/

#define NVIC_BASE  				(0xE000E100UL)

#define NVIC_ISER0				*(volatile uint32_t *)(NVIC_BASE)
#define NVIC_ISER1				*(volatile uint32_t *)(NVIC_BASE + 0x04)
#define NVIC_ISER2				*(volatile uint32_t *)(NVIC_BASE + 0x08)

#define NVIC_ICER0				*(volatile uint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1				*(volatile uint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2				*(volatile uint32_t *)(NVIC_BASE + 0x88)

#define NVIC_EN_EXTI0              (NVIC_ISER0 |= 1<<6)
#define NVIC_EN_EXTI1              (NVIC_ISER0 |= 1<<7)
#define NVIC_EN_EXTI2              (NVIC_ISER0 |= 1<<8)
#define NVIC_EN_EXTI3              (NVIC_ISER0 |= 1<<9)
#define NVIC_EN_EXTI4              (NVIC_ISER0 |= 1<<10)
#define NVIC_EN_EXTI9_5			   (NVIC_ISER0 |= 1<<23)

#define NVIC_EN_EXTI15_10		   (NVIC_ISER1 |= 1<<8)

#define NVIC_DIS_EXTI0              (NVIC_ICER0 |= 1<<6)
#define NVIC_DIS_EXTI1              (NVIC_ICER0 |= 1<<7)
#define NVIC_DIS_EXTI2              (NVIC_ICER0 |= 1<<8)
#define NVIC_DIS_EXTI3              (NVIC_ICER0 |= 1<<9)
#define NVIC_DIS_EXTI4              (NVIC_ICER0 |= 1<<10)
#define NVIC_DIS_EXTI9_5			(NVIC_ICER0 |= 1<<23)
#define NVIC_DIS_EXTI15_10		    (NVIC_ICER1 |= 1<<8)

/******************************************POINTER TO FUNCTION**************************************/

void  (*GPF[15])(void);

/******************************************PRIVATE FUNCTION**************************************/





#endif
