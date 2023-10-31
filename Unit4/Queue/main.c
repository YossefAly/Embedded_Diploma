/*
 * main.c
 *
 *  Created on: Oct 31, 2023
 *      Author: ALY
 */

#include "queue.h"
int main(void){
	unsigned int temp;
	unsigned int arr[5];
	unsigned int index;
	Queue_t Queue;
	Queue_init(&Queue,arr,5);
	for(index=0;index<5;index++){
		Queue_enqueue(&Queue,index);
		printf("%d\n",index);
	}
	for(index=0;index<5;index++){
		Queue_dequeue(&Queue,&temp);
		printf("%d\n",temp);
	}

return 0;}
