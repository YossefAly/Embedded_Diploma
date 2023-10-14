/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: ALY
 */
#include "stdio.h"
#include "string.h"

void EX1();
void EX2();
void EX3();
int main(){

/*	EX1();
	EX2();*/
	EX3();
	return 0;
}
void EX1(){
	char letter;
	int count=0;
	int index;
	char string[100];
	printf("Enter a string : ");
	fflush(stdout);
	gets(string);
	printf("Enter a character to find frequency : ");
	fflush(stdout);
	scanf("%c",&letter);
	for(index=0;index<strlen(string);index++){
		if(string[index]==letter){
			count++;
		}
	}
	printf("frequency of %c : %d",letter,count);
}
void EX2(){
	int count=0;
	int index;
	char string[100];
	printf("Enter a string : ");
	fflush(stdout);
	gets(string);
	for(index=0;string[index]!='\0';index++){
				count++;
		}
	printf("Length of string : %d",count);
}
void EX3(){
	int index;
	char string[100];
	printf("Enter a string : ");
	fflush(stdout);
	gets(string);
	for(index=0;(index<strlen(string)/2);index++){
					string[index]=string[index]+string[strlen(string)-index-1];
					string[strlen(string)-index-1]=string[index]-string[strlen(string)-index-1];
					string[index]=string[index]-string[strlen(string)-index-1];
			}
	printf("Reverse String is : %s",string);
}
