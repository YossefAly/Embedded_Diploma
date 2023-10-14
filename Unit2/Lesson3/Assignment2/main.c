/*
 * main.c
 *
 *  Created on: Oct 12, 2023
 *      Author: ALY
 */


#include "stdio.h"
void EX1();
void EX2();
void EX3();
void EX4();
void EX5();
void EX6();
void EX7();
void EX8();
int main(){
	/*EX1();*/
	/*EX2();
	EX3();
	EX4();
	EX5();
	EX6();
	EX7();*/
	EX8();
	return 0;
}
void EX1(){
	int number;
	printf("Enter an integer u want to check :");
	fflush(stdout);
	scanf("%d",&number);
	printf("%d is %c",number,(number%2==0)?'e':'o');

}
void EX2(){
	char character;
	printf("Enter a character u want to check :");
	fflush(stdout);
	scanf("%c",&character);
	switch(character){
		case 'a':
			printf("%c is a vowel",character);
			break;
		case 'e':
			printf("%c is a vowel",character);
			break;
		case 'i':
			printf("%c is a vowel",character);
			break;
		case 'o':
			printf("%c is a vowel",character);
			break;
		case 'u':
			printf("%c is a vowel",character);
			break;
		case 'A':
			printf("%c is a vowel",character);
			break;
		case 'E':
			printf("%c is a vowel",character);
			break;
		case 'I':
			printf("%c is a vowel",character);
			break;
		case 'O':
			printf("%c is a vowel",character);
			break;
		case 'U':
			printf("%c is a vowel",character);
			break;
		default:
			printf("%c is a constant",character);
			break;
	}
}
void EX3(){
	float a,b,c;
	printf("Enter Three Numbers :");
	fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if((a>b)&&(a>c)){
		printf("Largest Number is %f",a);
	}
	else if((b>a)&&(b>c)){
		printf("Largest Number is %f",b);
	}
	else if((c>a)&&(c>b)){
		printf("Largest Number is %f",c);
	}
	else {
		printf("Two or more numbers are equal");
	}
}
void EX4(){
	float a;
	printf("Enter a number to check :");
	fflush(stdout);
	scanf("%f",&a);
	if(a>0){
		printf("%f is positive",a);
	}
	else if(a<0){
		printf("%f is negative",a);
	}
	else {
		printf("You entered zero");
	}
}
void EX5(){
	char a;
	printf("Enter a character to check :");
	fflush(stdout);
	scanf("%c",&a);
	if((a>64)&&(a<123)){
		printf("%c is an alphabet",a);
	}
	else {
		printf("%c is not an alphabet",a);
	}
}
void EX6(){
	int a;
	printf("Enter an integer :");
	fflush(stdout);
	scanf("%d",&a);
	int i;
	int sum=0;
	for(i=a;i>0;i--){
		sum+=i;
	}
	printf("Sum = %d",sum);
}
void EX7(){
	int a;
	printf("Enter an integer :");
	fflush(stdout);
	scanf("%d",&a);
	int product=1;
	if(a<0){
		printf("Error!!! Factorial of negative number doesnt exist");
	}
	else{
		int i;
		for(i=a;i>0;i--){
			product*=i;
		}
		printf("Factorial = %d",product);
	}

}
void EX8(){
	char operator;
	float number1,number2;
	printf("Enter the operator either + or - or * or / :");
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two operand :");
	fflush(stdout);
	scanf("%f%f",&number1,&number2);
	switch(operator){
		case '+':
			printf("%f %c %f = %f",number1,operator,number2,number1+number2);
			break;
		case '-':
			printf("%f %c %f = %f",number1,operator,number2,number1-number2);
			break;
		case '*':
			printf("%f %c %f = %f",number1,operator,number2,number1*number2);
			break;
		case '/':
			printf("%f %c %f = %f",number1,operator,number2,number1/number2);
			break;
		default:
			printf("No operator is entered");
			break;
	}
}
