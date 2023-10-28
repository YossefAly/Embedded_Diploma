/*startup_cortexM3.s
Yossef
*/

/*SRAM 0x20000000*/
.section .vectors
.word 0x20001000
.word _reset /*1 reset*/
.word Vector_handler /*2 NMI*/
.word Vector_handler /*3 Hard Fault*/
.word Vector_handler  /*4 MM fault*/
.word Vector_handler /*5 Bus Fault*/
.word Vector_handler /*6 Usage Fault*/
.word Vector_handler /*7 RESERVED*/
.word Vector_handler /*8 RESERVED*/
.word Vector_handler /*9 RESERVED*/

.section .text
_reset:
	bl main
	b .
.thumb_func
Vector_handler:
	b _reset