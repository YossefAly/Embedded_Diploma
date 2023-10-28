/*startup.c yossef*/

#include <stdint.h>

void Reset_Handler();
void NMI_Handler() __attribute__ ((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__ ((weak,alias("Default_Handler")));
void MM_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault()__attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));

extern unsigned int _stack_top ;

uint32_t vectors[] __attribute__((section(".vectors")))  ={
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler,
	
};
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(){
	unsigned int  datasize = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	unsigned char * psrc = (unsigned char*)&_E_text;
	unsigned char * pdst = (unsigned char*)&_S_data;
	int i;
	for(i=0;i<datasize;i++){
		
		*((unsigned char*)psrc++)=*((unsigned char*)pdst++);
	}
    unsigned int bsssize=(unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	psrc = (unsigned char*)&_S_bss;
	for(i=0;i<bsssize;i++){
		*((unsigned char*)psrc++)=(unsigned char)0;
	}
	
	
	
	main();
}
void Default_Handler(){
	Reset_Handler();
}