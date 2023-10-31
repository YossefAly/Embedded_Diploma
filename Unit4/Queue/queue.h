/*
 * queue.h
 *
 *  Created on: Oct 31, 2023
 *      Author: ALY
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "stdio.h"
/*User Config */
typedef unsigned int type_t;
/*Type definitions*/
typedef struct{
	unsigned int length;
	unsigned int elements;
	type_t* head;
	type_t* base;
	type_t* tail;
}Queue_t;

typedef enum{
	Queue_Work,
	Queue_Null,
	Queue_Full,
	Queue_Empty
}Queue_t_Status;

/*APIS*/

Queue_t_Status Queue_enqueue(Queue_t*Queue,type_t element);
Queue_t_Status Queue_dequeue(Queue_t*Queue,type_t* element);
Queue_t_Status Queue_init(Queue_t*Queue,type_t* arr,unsigned int  length);


#endif /* QUEUE_H_ */
