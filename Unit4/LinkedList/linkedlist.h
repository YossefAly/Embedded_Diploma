/*
 * linkedlist.h
 *
 *  Created on: Nov 2, 2023
 *      Author: ALY
 */
 
 #ifndef _LINKEDLSIT_h
 #define _LINKEDLSIT_h
 
 #include "stdio.h"
 #include "stdlib.h"
 #include "string.h"
 #include "conio.h"
 
 /*Definitions*/
 typedef struct {
	 unsigned int ID;
	 float height;
	 char name[40];
 }Sdata;
  struct student{
	 Sdata data;
	 struct student* pNextStudent;
	 
 };
 typedef struct student Sstudent;
static Sstudent* gpFirstStudent=NULL;
 
 /*APIS*/
 void Add_Student();
 int Delete_Student();
 void Show_all();
 void Delete_all();
 void Get_Student();
 void Get_count();
 void Get_LastStudent();
 void Get_MiddleStudent();
 
 #endif