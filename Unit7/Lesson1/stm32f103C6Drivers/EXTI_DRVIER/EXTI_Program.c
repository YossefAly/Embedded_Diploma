/***********************************************INCLUDES********************************/


#include "EXTI_Interface.h"


/************************************************APIS**********************************/

 void EXTI_INIT(uint8_t CopyPort_ID,uint8_t CopyPin_ID,uint8_t CopyEXTI_Trigger_ID,void (*LPF)(void)){

	 UPDATE( CopyPort_ID, CopyPin_ID, CopyEXTI_Trigger_ID, LPF);

 }


 void EXTI_UPDATE(uint8_t CopyPort_ID,uint8_t CopyPin_ID,uint8_t CopyEXTI_Trigger_ID,void (*LPF)(void)){

	 UPDATE( CopyPort_ID, CopyPin_ID, CopyEXTI_Trigger_ID, LPF);

 }

 /**************************************************************************************
 	@Function EXTI_DEINIT
 	@Descripton:This Function is used to Disable EXTI
 	@Param:	nothing
 	@return:nothing
 	@Note:none
 */
 void EXTI_DEINIT(void){

	 EXTI->IMR   =   0x00000000;
	 EXTI->EMR   =   0x00000000;

	 EXTI->RTSR  =   0x00000000;

	 EXTI->FTSR  =   0x00000000;
	 EXTI->SWIER =   0x00000000;

	 EXTI->PR    =   0xFFFFFFFF;

	 NVIC_DIS_EXTI0    ;
	 NVIC_DIS_EXTI1    ;
	 NVIC_DIS_EXTI2    ;
	 NVIC_DIS_EXTI3    ;
	 NVIC_DIS_EXTI4    ;
	 NVIC_DIS_EXTI9_5  ;
	 NVIC_DIS_EXTI15_10;
 }

 void UPDATE(uint8_t CopyPort_ID,uint8_t CopyPin_ID,uint8_t CopyEXTI_Trigger_ID,void *LPF(void)){

 	EXTI_Enable(CopyPort_ID,CopyPin_ID);

 	if(CopyPin_ID==0){
 		NVIC_EN_EXTI0;
 	}
 	else if(CopyPin_ID==1){
 		NVIC_EN_EXTI1;
 	}
 	else if(CopyPin_ID==2){
 		NVIC_EN_EXTI2;
 	}
 	else if(CopyPin_ID==3){
 		NVIC_EN_EXTI3;
 	}
 	else if(CopyPin_ID==4){
 		NVIC_EN_EXTI4;
 	}
 	else if ((CopyPin_ID>4)&&(CopyPin_ID<10)){
 		NVIC_EN_EXTI9_5;
 	}
 	else if ((CopyPin_ID>9)&&(CopyPin_ID<16)){
 		NVIC_EN_EXTI15_10;
 	}

 	switch(CopyEXTI_Trigger_ID){
 	case 0:
 		EXTI->RTSR |= 1 << CopyPin_ID;
 		EXTI->FTSR &=~ 1 << CopyPin_ID;
 		break;
 	case 1:
 		EXTI->FTSR |= 1 << CopyPin_ID;
 		EXTI->RTSR &=~ 1 << CopyPin_ID;
 		break;
 	case 2:
 		EXTI->FTSR |= 1 << CopyPin_ID;
 		EXTI->RTSR |= 1 << CopyPin_ID;
 		break;
 	default:
 		break;
 	}
 	EXTI->IMR |= 1<<CopyPin_ID;

 	GPF[CopyPin_ID] = LPF;
 }

 void EXTI0_IRQHandler(void){

 	EXTI->PR = 1<<0;

 	GPF[0]();
 }
 void EXTI1_IRQHandler(void){

 	EXTI->PR = 1<<1;

 	GPF[1]();
 }
 void EXTI2_IRQHandler(void){

 	EXTI->PR = 1<<2;

 	GPF[2]();

 }
 void EXTI3_IRQHandler(void){

 	EXTI->PR = 1<<3;

 	GPF[3]();

 }
 void EXTI4_IRQHandler(void){

 	EXTI->PR = 1<<4;

 	GPF[4]();

 }
 void EXTI9_5_IRQHandler(void){

 	if(EXTI->PR & 1<<5){EXTI->PR |= 1<<5 ; 	GPF[5]();}
 	if(EXTI->PR & 1<<6){EXTI->PR |= 1<<6 ; 	GPF[6]();}
 	if(EXTI->PR & 1<<7){EXTI->PR |= 1<<7 ; 	GPF[7]();}
 	if(EXTI->PR & 1<<8){EXTI->PR |= 1<<8 ; 	GPF[8]();}
 	if(EXTI->PR & 1<<9){EXTI->PR |= 1<<9 ; 	GPF[9]();}

 }
 void EXTI15_10_IRQHandler(void){

 	if(EXTI->PR & 1<<10){EXTI->PR |= 1<<10 ; 	GPF[10]();}
 	if(EXTI->PR & 1<<11){EXTI->PR |= 1<<11 ; 	GPF[11]();}
 	if(EXTI->PR & 1<<12){EXTI->PR |= 1<<12 ; 	GPF[12]();}
 	if(EXTI->PR & 1<<13){EXTI->PR |= 1<<13 ; 	GPF[13]();}
 	if(EXTI->PR & 1<<14){EXTI->PR |= 1<<14 ; 	GPF[14]();}
 	if(EXTI->PR & 1<<15){EXTI->PR |= 1<<15 ; 	GPF[15]();}
 }
