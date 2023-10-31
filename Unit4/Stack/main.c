/*
 * main.c
 *
 *  Created on: Oct 31, 2023
 *      Author: ALY
 */


#include "stack.h"

int main(void){
	int index;
	unsigned int arr[5];
	unsigned int temp;
	Stack_t Stack;
	Stack_init(&Stack,arr,5);
	for(index=0;index<5;index++){
		Stack_push(&Stack,index);
		printf("%d\n",index);
	}
	for(index=0;index<5;index++){
		Stack_pop(&Stack,&temp);
		printf("%d\n",temp);
	}

	return 0;
}
