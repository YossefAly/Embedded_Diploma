/*
 * stack.h
 *
 *  Created on: Oct 31, 2023
 *      Author: ALY
 */

#ifndef STACK_H_
#define STACK_H_
#include "stdio.h"

/*Type definitions*/
typedef struct{
	unsigned int length;
	unsigned int elements;
	unsigned int* head;
	unsigned int* base;

}Stack_t;

typedef enum{
	Stack_Work,
	Stack_Null,
	Stack_Full,
	Stack_Empty
}Stack_t_Status;

/*APIS*/

Stack_t_Status Stack_push(Stack_t*Stack,unsigned int element);
Stack_t_Status Stack_pop(Stack_t*Stack,unsigned int* element);
Stack_t_Status Stack_init(Stack_t*Stack,unsigned int* arr,unsigned int length);








#endif /* STACK_H_ */
