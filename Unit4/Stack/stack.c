/*
 * stack.c
 *
 *  Created on: Oct 31, 2023
 *      Author: ALY
 */

#include "stack.h"

Stack_t_Status Stack_push(Stack_t* Stack,unsigned int element){
	/*Validation*/
	if((Stack->base||Stack->head)==(unsigned int*)NULL)
		return Stack_Null;
	else if(Stack->elements==Stack->length)
		return Stack_Full;
	else{
		*(Stack->head)++=element;Stack->elements++;return Stack_Work;}

}
Stack_t_Status Stack_pop(Stack_t*Stack,unsigned int*element){
	if((Stack->base||Stack->head)==(unsigned int*)NULL)
		return Stack_Null;
	else if(Stack->elements==0)
		return Stack_Empty;
	else{
		Stack->head--;*element=*(Stack->head);Stack->elements--;return Stack_Work;}
}
Stack_t_Status Stack_init(Stack_t*Stack,unsigned int*element,unsigned int length){
		if(element==NULL)
			return Stack_Null;
		else{
		Stack->base=element;
		Stack->head=element;
		Stack->length=length;
		Stack->elements=0;
		return Stack_Work;}
}
