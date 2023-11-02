
#include "linkedlist.h"


 void Add_Student(){
	 char text[40];
	 Sstudent*pNewStudent;
	 Sstudent*pLastStudent;
	 if(!gpFirstStudent){
		 pNewStudent=(Sstudent*)malloc(sizeof(Sstudent));
		 gpFirstStudent=pNewStudent;
	 }else{
		 pLastStudent=gpFirstStudent;
		 while(pLastStudent->pNextStudent)
			 pLastStudent=pLastStudent->pNextStudent;
		  pNewStudent=(Sstudent*)malloc(sizeof(Sstudent));
		  pLastStudent->pNextStudent=pNewStudent;
	 }
	printf("Enter Student ID\n");
	gets(text);
	pNewStudent->data.ID=atoi(text);
	printf("Enter Student Name\n");
	gets(pNewStudent->data.name);
	printf("Enter Student Heigth\n");
	gets(text);
	pNewStudent->data.height=atof(text);
	pNewStudent->pNextStudent=NULL;
 }
 int Delete_Student(){
	 char text[40];
	 unsigned int ID;
	 Sstudent*pSelected;
	 Sstudent*pPrev;
	 if(gpFirstStudent){
		 pSelected=gpFirstStudent->pNextStudent;
		 pPrev=gpFirstStudent;
		 printf("Enter the Student ID\n");
		 gets(text);
		 ID=atoi(text);
		 	if(pPrev->data.ID==ID){
			gpFirstStudent=pSelected;
			free(pSelected);
			printf("Student Deleted\n");
			return 1;
		 }
		 while(pSelected->data.ID!=ID){
			pPrev =pSelected;
			pSelected=pSelected->pNextStudent;
			if(!pSelected){
				printf("No Student with this ID\n");
				return 0;}
		 }
		 pPrev->pNextStudent=pSelected->pNextStudent;
		 free(pSelected);
		 printf("Student Deleted\n");
		 return 1;
	 }
	 else
		 return 0;
 }
 void Show_all(){
	 Sstudent*pSelected=gpFirstStudent;
	 unsigned int count=0;
	 while(pSelected){
		 printf("Student Number %d\n",count+1);
		 printf("Student Name: %s\n",pSelected->data.name);
		 printf("Student ID: %d\n",pSelected->data.ID);
		 printf("Student Height: %f\n\n",pSelected->data.height);
		 pSelected=pSelected->pNextStudent;
		 count++;
	 }
 }
 void Delete_all(){
	 Sstudent*pSelected=gpFirstStudent;
	 
	 while(pSelected){
		 Sstudent*temp=pSelected;
		 pSelected=pSelected->pNextStudent;
		 free(temp);
	 }
	 gpFirstStudent=NULL;
	 printf("All Students Deleted\n");
 }
  void Get_Student(){
	  printf("Enter Student Index: \n");
	  char text[40];
	  gets(text);
	  int count=atoi(text);
	  Sstudent*pSelected=gpFirstStudent;
	     unsigned int current=1;
	   	 while(pSelected&&current!=count){
		 pSelected=pSelected->pNextStudent;
		 current++;
	 }
		if(pSelected&&current==count){
		 printf("Student Number %d\n",current);
		 printf("Student Name: %s\n",pSelected->data.name);
		 printf("Student ID: %d\n",pSelected->data.ID);
		 printf("Student Height: %f\n\n",pSelected->data.height);
		}
		else{
			printf("Wrong index\n");
		}
  }
  void Get_count(){
	  int count=0;
	  Sstudent*pSelected=gpFirstStudent;
	  while(pSelected){
		  count++;
		  pSelected=pSelected->pNextStudent;
	  }

	  printf("Number of students is: %d\n",count);
	  
  }
   void Get_LastStudent(){
	   int current=0;
	  printf("Enter Student Index: \n");
	  char text[40];
	  gets(text);
	  int count=atoi(text);
	  Sstudent*pSelected=gpFirstStudent;
	  while(pSelected){
		  current++;
		  pSelected=pSelected->pNextStudent;
	  }
	  pSelected=gpFirstStudent;
	  current=current-count;
	  printf("%d\n",current);
	  printf("%d\n",count);
	  if(current>=0){
		while(current){
			pSelected=pSelected->pNextStudent;
			current--;
		}
		 printf("Student Number %d\n",count);
		 printf("Student Name: %s\n",pSelected->data.name);
		 printf("Student ID: %d\n",pSelected->data.ID);
		 printf("Student Height: %f\n\n",pSelected->data.height);
	  }
	  else
		  printf("Wrong index\n");
	  
   }
   void Get_MiddleStudent(){
	   if(gpFirstStudent){
	   	   int current=0;
		   int count=0;
		   Sstudent*pSelected=gpFirstStudent;
	  while(pSelected){
		  current++;
		  pSelected=pSelected->pNextStudent;
	  }
	  pSelected=gpFirstStudent;
	   if(current%2==0){
		   current=(current/2)+1;
		   count=current;
		while(current){
			pSelected=pSelected->pNextStudent;
			current--;
		}
		 printf("Student Number %d\n",current);
		 printf("Student Name: %s\n",pSelected->data.name);
		 printf("Student ID: %d\n",pSelected->data.ID);
		 printf("Student Height: %f\n\n",pSelected->data.height);
	  }
	  else
		current=(current/2);
		count=current;
		while(current){
			pSelected=pSelected->pNextStudent;
			current--;
		}
		 printf("Student Number %d\n",count);
		 printf("Student Name: %s\n",pSelected->data.name);
		 printf("Student ID: %d\n",pSelected->data.ID);
		 printf("Student Height: %f\n\n",pSelected->data.height);
	   }
	   else{
		   printf("Empty list\n");
	   }
	  
   }