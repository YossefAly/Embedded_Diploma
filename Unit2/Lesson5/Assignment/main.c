/*
 * main.c
 *
 *  Created on: Oct 15, 2023
 *      Author: ALY
 */
#include "stdio.h"

void Prime(int,int);
int Recursion(int);
void Reverse();
int power(int,int);
int main(){
	/*int a,b;
	printf("Enter Two numbers (Intervals) : ");
	fflush(stdout);
	scanf("%d%d",&a,&b);
	Prime(a,b);*/
/*	int a;

	printf("Enter a Positive integer :");
	fflush(stdout);
	scanf("%d",&a);
	printf("Factorial of %d : %d",a,Recursion(a));*/
/*	printf("Enter a Sentence : ");
	fflush(stdout);
	Reverse();*/
	int a,b;
	printf("Enter base number : ");
	fflush(stdout);
	scanf("%d",&a);
	printf("Enter power number(positive integer) : ");
	fflush(stdout);
	scanf("%d",&b);
	printf("%d^%d = %d",a,b,power(a,b));
	return 0;
}
void Prime(int a,int b){
	int index=a;
	if(index%2==0){
		index++;
	}
	for(;index<b;index+=2){
		printf("%d ",index);
	}
}
int Recursion(int a){
	if(a<2)
		return a;
	else
		return a*Recursion(a-1);
}
void Reverse(){
    char character;
    scanf("%c", &character);
    if (character != '\n') {
        Reverse();
        printf("%c", character);
}
}
int power(int a,int b){
	if(b<2)
		return a;
	else{
		b--;
		return a*power(a,b);
	}


}
