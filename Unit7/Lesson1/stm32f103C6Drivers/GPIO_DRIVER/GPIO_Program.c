#ifndef GPIO_CONFIG_H
#define _GPIO_CONFIG_H

/***********************************************INCLUDES********************************/
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


/************************************************APIS**********************************/

/**************************************************************************************
	@Function Name:GPIO_INIT
	@Descripton:This Function is used to initialize a pin
	@Param:	-PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
			-PINID :where it can be initialized by :PIN0-PIN15
			-PINMODE:where it can be initialized by :
					 INPUT_ANALOG
	 	 	 	 	 INPUT_FLOATING
					 INPUT_PULLUP
					 INPUT_PULLDOWN
					 OUTPUT_PUSHPULL
					 OUTPUT_OPENDRAIN
					 AF_PUSHPULL
					 AF_OPENDRAIN
	@return:nothing
	@Note:Not all ports have 16 pins
*/

void GPIO_INIT(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID,uint8_t Copy_u8PIN_MODE){
	/*Input Validation*/
	if(Copy_u8PORT_ID>IOD){
		//DO NOTHING
	}
	else{
		switch(Copy_u8PORT_ID){
		case IOA:
			if((Copy_u16PIN_ID>PIN15)||(Copy_u8PIN_MODE>AF_OPENDRAIN)){
				//Do nothing
			}
			else{
				if(Copy_u16PIN_ID<PIN8){
					GPIOA->CRL &= ~(3<<Copy_u16PIN_ID*4);
					GPIOA->CRL &=~(3<<(Copy_u16PIN_ID*4+2));
					switch (Copy_u8PIN_MODE){
					case INPUT_ANALOG:
						GPIOA->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRL |= INPUT_ANALOG << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_FLOATING:
						GPIOA->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRL |= INPUT_FLOATING << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLUP:
						GPIOA->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRL |= INPUT_PULLUP << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLDOWN:
						GPIOA->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRL |= INPUT_PULLDOWN << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_PUSHPULL:
						GPIOA->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRL |= (OUTPUT_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_OPENDRAIN:
						GPIOA->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRL |= (OUTPUT_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_PUSHPULL:
						GPIOA->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRL |= (AF_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_OPENDRAIN:
						GPIOA->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRL |= (AF_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					default:
						break;//DO NTH
					}
				}
				else if((Copy_u16PIN_ID>PIN8)&&(Copy_u16PIN_ID<=PIN15)){
					Copy_u16PIN_ID=Copy_u16PIN_ID-8;
					GPIOA->CRH &= ~(3<<Copy_u16PIN_ID*4);
					GPIOA->CRH &=~(3<<(Copy_u16PIN_ID*4+2));
					switch (Copy_u8PIN_MODE){
					case INPUT_ANALOG:
						GPIOA->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRH |= INPUT_ANALOG << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_FLOATING:
						GPIOA->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRH |= INPUT_FLOATING << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLUP:
						GPIOA->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRH |= INPUT_PULLUP << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLDOWN:
						GPIOA->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRH |= INPUT_PULLDOWN << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_PUSHPULL:
						GPIOA->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRH |= (OUTPUT_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_OPENDRAIN:
						GPIOA->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRH |= (OUTPUT_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_PUSHPULL:
						GPIOA->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRH |= (AF_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_OPENDRAIN:
						GPIOA->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOA->CRH |= (AF_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					default:
						break;//DO NTH
					}
				}
			}
			break;
		case IOB:
			if((Copy_u16PIN_ID>PIN15)||(Copy_u8PIN_MODE>AF_OPENDRAIN)){
				//Do nothing
			}
			else{
				if(Copy_u16PIN_ID<PIN8){
					GPIOB->CRL &= ~(3<<Copy_u16PIN_ID*4);
					GPIOB->CRL &=~(3<<(Copy_u16PIN_ID*4+2));
					switch (Copy_u8PIN_MODE){
					case INPUT_ANALOG:
						GPIOB->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRL |= INPUT_ANALOG << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_FLOATING:
						GPIOB->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRL |= INPUT_FLOATING << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLUP:
						GPIOB->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRL |= INPUT_PULLUP << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLDOWN:
						GPIOB->CRL |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRL |= INPUT_PULLDOWN << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_PUSHPULL:
						GPIOB->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRL |= (OUTPUT_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 1);
						break;
					case OUTPUT_OPENDRAIN:
						GPIOB->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRL |= (OUTPUT_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_PUSHPULL:
						GPIOB->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRL |= (AF_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_OPENDRAIN:
						GPIOB->CRL |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRL |= (AF_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					default:
						break;//DO NTH
					}
				}
				else if((Copy_u16PIN_ID>PIN8)&&(Copy_u16PIN_ID<=PIN15)){
					Copy_u16PIN_ID=Copy_u16PIN_ID-8;
					GPIOB->CRH &= ~(3<<Copy_u16PIN_ID*4);
					GPIOB->CRH &= ~(3<<(Copy_u16PIN_ID*4+2));
					switch (Copy_u8PIN_MODE){
					case INPUT_ANALOG:
						GPIOA->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOA->CRH |= INPUT_ANALOG << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_FLOATING:
						GPIOB->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRH |= INPUT_FLOATING << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLUP:
						GPIOB->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRH |= INPUT_PULLUP << (Copy_u16PIN_ID*4 + 2);
						break;
					case INPUT_PULLDOWN:
						GPIOB->CRH |= 0 << Copy_u16PIN_ID*4;
						GPIOB->CRH |= INPUT_PULLDOWN << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_PUSHPULL:
						GPIOB->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRH |= (OUTPUT_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case OUTPUT_OPENDRAIN:
						GPIOB->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRH |= (OUTPUT_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_PUSHPULL:
						GPIOB->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRH |= (AF_PUSHPULL-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					case AF_OPENDRAIN:
						GPIOB->CRH |= OUTPUT_LS << Copy_u16PIN_ID*4;
						GPIOB->CRH |= (AF_OPENDRAIN-4) << (Copy_u16PIN_ID*4 + 2);
						break;
					default:
						break;//DO NTH
					}
				}
			}
			break;
		case IOC:
			break;
		case IOD:
			break;
		}
	}
}

/**************************************************************************************
	@Function Name:GPIO_DEINIT
	@Descripton:This Function is used to reset a port
	@Param:	-PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
	@return:nothing
	@Note:none
*/

void GPIO_DEINIT(uint8_t Copy_u8PORT_ID){

	switch(Copy_u8PORT_ID){
	case IOA:
		GPIOA->CRL  =  0x44444444;
		GPIOA->CRH  =  0x44444444;
		GPIOA->IDR  =  0x00000000;
		GPIOA->ODR  =  0x00000000;
		GPIOA->BSRR =  0x00000000;
		GPIOA->BRR  =  0x00000000;
		GPIOA->LCKR =  0x00000000;
		break;
	case IOB:
		GPIOB->CRL  =  0x44444444;
		GPIOB->CRH  =  0x44444444;
		GPIOB->IDR  =  0x00000000;
		GPIOB->ODR  =  0x00000000;
		GPIOB->BSRR =  0x00000000;
		GPIOB->BRR  =  0x00000000;
		GPIOB->LCKR =  0x00000000;
		break;
	case IOC:
		GPIOC->CRL  =  0x44444444;
		GPIOC->CRH  =  0x44444444;
		GPIOC->IDR  =  0x00000000;
		GPIOC->ODR  =  0x00000000;
		GPIOC->BSRR =  0x00000000;
		GPIOC->BRR  =  0x00000000;
		GPIOC->LCKR =  0x00000000;
		break;
	case IOD:
		GPIOD->CRL  =  0x44444444;
		GPIOD->CRH  =  0x44444444;
		GPIOD->IDR  =  0x00000000;
		GPIOD->ODR  =  0x00000000;
		GPIOD->BSRR =  0x00000000;
		GPIOD->BRR  =  0x00000000;
		GPIOD->LCKR =  0x00000000;
	default:
		break;
	}

}

/**************************************************************************************
	@Function GPIO_READ_PIN
	@Descripton:This Function is used to read a pin from a port
	@Param:	-PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
			-PINID :where it can be initialized by :PIN0-PIN15
	@return: HIGH or LOW
	@Note:none
*/

uint16_t GPIO_READ_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID){

	uint16_t PinStatus;
	switch(Copy_u8PORT_ID){
	case IOA:
		PinStatus=((GPIOA->IDR)&(1<<Copy_u16PIN_ID));
		break;
	case IOB:
		PinStatus=((GPIOB->IDR)&(1<<Copy_u16PIN_ID));
		break;
	case IOC:
		PinStatus=((GPIOC->IDR)&(1<<Copy_u16PIN_ID));
		break;
	case IOD:
		PinStatus=((GPIOD->IDR)&(1<<Copy_u16PIN_ID));
		break;
	default:
		PinStatus=0;
		break;
	}
	return PinStatus;
}

/**************************************************************************************
	@Function GPIO_READ_PORT
	@Descripton:This Function is used to read the port value
	@Param:	-PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
	@return: from 0x0000->0xFFFF
	@Note:none
*/

uint16_t GPIO_READ_PORT(uint8_t Copy_u8PORT_ID){

	uint16_t Portstatus;
	switch(Copy_u8PORT_ID){
	case IOA:
		Portstatus=(GPIOA->IDR);
		break;
	case IOB:
		Portstatus=(GPIOB->IDR);
		break;
	case IOC:
		Portstatus=(GPIOC->IDR);
		break;
	case IOD:
		Portstatus=(GPIOD->IDR);
		break;
	default:
		break;
	}
	return Portstatus;
}


/**************************************************************************************
	@Function GPIO_WRITE_PIN
	@Descripton:This Function is used to write on a pin
	@Param:	-PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
			-PINID :where it can be initialized by :PIN0-PIN15
			-VALUE : HIGH or LOW
	@return: none
	@Note:none
*/

void GPIO_WRITE_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID,uint8_t Copy_u8value){

	switch(Copy_u8PORT_ID){
	case IOA:
		if(Copy_u8value==HIGH)
		GPIOA->BSRR = (uint32_t)HIGH<<Copy_u16PIN_ID;
		else{
		GPIOA->BSRR = (uint32_t)HIGH<<(Copy_u16PIN_ID+16);
		}
		break;
	case IOB:
		if(Copy_u8value==HIGH)
		GPIOB->BSRR = (uint32_t)HIGH<<Copy_u16PIN_ID;
		else{
		GPIOB->BSRR = (uint32_t)HIGH<<(Copy_u16PIN_ID+16);
		}
		break;
	case IOC:
		if(Copy_u8value==HIGH)
		GPIOC->BSRR = (uint32_t)HIGH<<Copy_u16PIN_ID;
		else{
		GPIOC->BSRR = (uint32_t)HIGH<<(Copy_u16PIN_ID+16);
		}
		break;
	case IOD:
		if(Copy_u8value==HIGH)
		GPIOD->BSRR = (uint32_t)HIGH<<Copy_u16PIN_ID;
		else{
		GPIOD->BSRR = (uint32_t)HIGH<<(Copy_u16PIN_ID+16);
		}
		break;
	default:
		break;
	}

}

/**************************************************************************************
	@Function GPIO_WRITE_PORT
	@Descripton:This Function is used to write on a PORT
	@Param:	-PORTID:where it can be initialized by :IOA,IOB
			-VALUE : from 0x0000->0xFFFF
	@return:none
	@Note:PORTC AND PORTD CAN BE USED ONLY IF PINS ARENT RESERVED
*/

void GPIO_WRITE_Port(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16value){

	switch(Copy_u8PORT_ID){
		case IOA:
			GPIOA->ODR = (uint32_t)Copy_u16value;
			break;
		case IOB:
			GPIOB->ODR = (uint32_t)Copy_u16value;
			break;
		case IOC:
			GPIOC->ODR = (uint32_t)Copy_u16value;
			break;
		case IOD:
			GPIOD->ODR = (uint32_t)Copy_u16value;
			break;
		default:
			break;
		}

}

/**************************************************************************************
	@Function GPIO_TOGGLE_PIN
	@Descripton:This Function is used to toggle a PIN
	@Param: -PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
			-PINID :where it can be initialized by :PIN0-PIN15
	@return:none
	@Note:none
*/

void GPIO_TOGGLE_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID){

	switch(Copy_u8PORT_ID){
			case IOA:
				GPIOA->ODR ^= HIGH<<Copy_u16PIN_ID;
				break;
			case IOB:
				GPIOB->ODR ^= HIGH<<Copy_u16PIN_ID;
				break;
			case IOC:
				GPIOC->ODR ^= HIGH<<Copy_u16PIN_ID;
				break;
			case IOD:
				GPIOD->ODR ^= HIGH<<Copy_u16PIN_ID;
				break;
			default:
				break;
			}

}


/**************************************************************************************
	@Function GPIO_LOCK_PIN
	@Descripton:This Function is used to Lock a PIN (Have the same mode until next reset)
	@Param: -PORTID:where it can be initialized by :IOA,IOB,IOC,IOD
			-PINID :where it can be initialized by :PIN0-PIN15
	@return:none
	@Note:none
*/

void GPIO_LOCK_PIN(uint8_t Copy_u8PORT_ID,uint16_t Copy_u16PIN_ID){}

#endif
