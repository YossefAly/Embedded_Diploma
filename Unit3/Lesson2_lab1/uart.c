#include "uart.h"

//define Uart0 Data register
#define UART0DR *((volatile unsigned int*)((unsigned int*)0x101f1000)) 

void Uart_Send(unsigned char* PTX_string){
	
	while(*PTX_string!='\0'){
		UART0DR=(unsigned int)*PTX_string;
		PTX_string++;
	}
}