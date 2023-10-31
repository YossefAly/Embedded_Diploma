/*startup.c yossef*/

#include <stdint.h>

void Reset_Handler();
extern int main(void);
void Default_Handler(){
	Reset_Handler();
}
void NMI_Handler() __attribute__ ((weak,alias("Default_Handler")));
void H_fault_Handler()__attribute__ ((weak,alias("Default_Handler")));
void MM_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault()__attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));


static unsigned long Stack_top[256] ;

	void (*const gpf_vectors[])() __attribute__((section(".vectors")))=
	{
		(void(*)()) ((unsigned long)Stack_top+sizeof(Stack_top)),
		&Reset_Handler,
		&NMI_Handler,
		&H_fault_Handler,
		&MM_Fault_Handler,
		&Bus_Fault,
		&Usage_Fault_Handler,
		
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
    unsigned int bsssize=(unsigned char*)&_S_bss - (unsigned char*)&_E_bss ;
	psrc = (unsigned char*)&_S_bss;
	for(i=0;i<bsssize;++i){
		*((unsigned char*)psrc++)=(unsigned char)0;
	}
	main();
}
