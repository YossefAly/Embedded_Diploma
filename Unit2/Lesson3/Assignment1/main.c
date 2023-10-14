/*
 * main.c
 *
 *  Created on: Oct 10, 2023
 *      Author: ALY
 */

#include "stdio.h"

void EX1();
void EX2();
void EX3();
void EX4();
void EX5();
void EX6();
int main(){

	//EX1();
	//EX2();
	//EX3();
	//EX4();
	//EX5();
	EX6();//we can use a to temp varable to do that
	//EX7 The same as EX6
	return 0;
}
void EX1(){
	printf("Hello World");
}
void EX2(){
	int integer;
	printf("Enter an integer :");
	fflush(stdout);
	scanf("%d",&integer);
	printf("You Entered : %d",integer);
}
void EX3(){
	int integer1,integer2;
	printf("Enter Two Numbers :");
	fflush(stdout);
	scanf("%d %d",&integer1,&integer2);
	printf("sum : %d",integer1+integer2);
}
void EX4(){
	float float1,float2;
	printf("Enter Two Numbers :");
	fflush(stdout);
	scanf("%f %f",&float1,&float2);
	printf("Product : %f",float1*float2);
}
void EX5(){
	char character;
	printf("Enter a character :");
	fflush(stdout);
	scanf("%c",&character);
	printf("ASCII value of %c is %d",character,character);

}
void EX6(){
	float a,b;
	printf("Enter The value of a :");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter The value of b :");
	fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After Swapping,The value of a= %f\n",a);
	printf("After Swapping,The value of b= %f",b);
}
