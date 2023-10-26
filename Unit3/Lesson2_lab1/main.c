#include "uart.h"

unsigned char string[100]="Learn-in-depth:yossef";
unsigned char const string2[100]="Learn-in-depth:yossef";
int main(){
	
	Uart_Send(string);
	
	return 0;
}

