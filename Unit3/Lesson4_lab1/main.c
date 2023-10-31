

#define SYSCTL_RCGC2_R  *((volatile unsigned long*)0x400FE108)
#define GPIO_PORTF_DIR_R  *((volatile unsigned long*)0x40025400)
#define GPIO_PORTF_DEN_R  *((volatile unsigned long*)0x4002551C)
#define GPIO_PORTF_DATA_R  *((volatile unsigned long*)0x400253FC)

int main(void){
	SYSCTL_RCGC2_R|=0x20;
	volatile int dummy=0;
	
	GPIO_PORTF_DIR_R|=0x04;
	GPIO_PORTF_DEN_R|=0x04;
	GPIO_PORTF_DATA_R|=0x04;
	while(1){
		GPIO_PORTF_DATA_R^=0x04;
		for(dummy=0;dummy<20000;dummy++);
		
	}
	return 0;
}