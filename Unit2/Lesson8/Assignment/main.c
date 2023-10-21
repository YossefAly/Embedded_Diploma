/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: ALY
 */

#include "stdio.h"
#include "string.h"
void EX1();
void EX2();
void EX3();
void EX4();
void EX5();
int main(){

	/*EX1();
	EX2();
	EX3();
	EX4();*/
	EX5();
	return 0;
}
void EX1(){
	int m=29;
	printf("Address of m= 0x%p\n"
			"Value of m= %d\n",&m,m);
	int*ab=&m;
	printf("Address of pointer ab= 0x%p\n"
			"Value of pointer ab= %d\n",ab,*ab);
	m=34;
	printf("The value of m is assigned to 34 now\n"
			"Address of pointer ab= 0x%p\n"
			"Value of pointer ab= %d\n",ab,*ab);
	*ab=7;
	printf("The pointer vairable ab is assigned with the value 7 now\n"
			"Address of m= 0x%p\n"
			"Value of m= %d\n",ab,*ab);
}
void EX2(){
	int index;
	int x=65;
	int *px=&x;
	for(index=0;index<26;index++){
		printf("%c ",*px);
		*px+=1;
	}
}
void EX3(){
	int index;
	char string[100];
	char *pstring=string;
	printf("Enter a string : ");
	fflush(stdout);
	gets(string);
	for(index=0;(index<strlen(string)/2);index++){
					*(pstring+index)=*(pstring+index)+*(pstring+strlen(string)-index-1);
					*(pstring+strlen(string)-index-1)=*(pstring+index)-*(pstring+strlen(string)-index-1);
					*(pstring+index)=*(pstring+index)-*(pstring+strlen(string)-index-1);
			}
	printf("Reverse String is : %s",string);
}
void EX4(){
	int index;
	int number;
	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdout);
	scanf("%d",&number);
	int arr[number];
	printf("Input %d number of elements in the array,number\n",number);
	for(index=0;index<number;index++){
		printf("element - %d: ",index+1);
		fflush(stdout);
		scanf("%d",&arr[index]);
	}
	int*parr=&arr[number-1];
	printf("The elements of array in reverse order are :\n");
	for(index=number-1;index>=0;index--){
		printf("element - %d : %d\n",index+1,*parr);
		parr--;
	}
}
struct sInfo{
	char name[10];
	int ID;
};
void EX5(){
	struct sInfo* pstruct[5];
	struct sInfo Alex={"Alex",1002};
	pstruct[0]=&Alex;
	printf("Exmployee Name : %s\n",pstruct[0]->name);
	printf("Employee ID : %d",pstruct[0]->ID);
}
