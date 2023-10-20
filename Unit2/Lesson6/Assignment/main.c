/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: ALY
 */


#include "stdio.h"

struct Sinfo{
	int roll;
	float mark;
	char name[100];
};
struct Slength{
	int feet;
	float inch;
};
struct Scomplex{
	float real;
	float imag;
};
struct Scomplex AddComplex(struct Scomplex a,struct Scomplex b){
	struct Scomplex Add;
	Add.real=a.real+b.real;
	Add.imag=a.imag+b.imag;
	return Add;
};
struct Sstudents{
	struct Sinfo information[10];
};
void EX1();
void EX2();
void EX3();
void EX4();
#define Area(x) (3.14*x*x)
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
	struct Sinfo information;
	printf("Enter information of student\n");
	printf("Enter Name : ");
	fflush(stdout);
	scanf("%s",information.name);
	printf("Enter Roll : ");
	fflush(stdout);
	scanf("%d",&information.roll);
	printf("Enter mark : ");
	fflush(stdout);
	scanf("%f",&information.mark);
	printf("Displaying Information\n"
			"name: %s\n"
			"roll: %d\n"
			"mark :%.1f",information.name,information.roll,information.mark);
}
void EX2(){
	struct Slength Length1,Length2,sum;
	printf("Enter information of 1st distance\n"
			"Enter Feet: ");
	fflush(stdout);
	scanf("%d",&Length1.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&Length1.inch);

	printf("Enter information of 2st distance\n"
			"Enter Feet: ");
	fflush(stdout);
	scanf("%d",&Length2.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&Length2.inch);
	sum.inch=Length1.inch+Length2.inch;
	sum.feet=Length1.feet+Length2.feet;
	while(sum.inch>=12){
		sum.feet++;
		sum.inch-=12;}
	printf("Sum of distances: %d'-%.1f\" ",sum.feet,sum.inch);
	}
void EX3(){
	struct Scomplex First,Second,Result;
	printf("For 1st complex number\n"
			"Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&First.real,&First.imag);
	printf("For 2st complex number\n"
			"Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f%f",&Second.real,&Second.imag);
	Result=AddComplex(First,Second);
	if(Result.imag>0)
		printf("Sum= %.1f+%.1fi",Result.real,Result.imag);
	else
		printf("Sum= %.1f%.1fi",Result.real,Result.imag);
}
void EX4(){
	int index;
	struct Sstudents Students;
	printf("Enter information of Students:\n\n");
	for(index=0;index<3;index++){
		printf("For roll number %d\n",index+1);
		printf("Enter Name : ");
		fflush(stdout);
		scanf("%s",Students.information[index].name);
		printf("Enter mark : ");
		fflush(stdout);
		scanf("%f",&Students.information[index].mark);
	}
	printf("Displaying informations of students\n\n");
	for(index=0;index<3;index++){
		printf("Information for roll %d\n"
				"Name: %s\n"
				"mark: %.1f\n\n",index+1,Students.information[index].name,Students.information[index].mark);
	}

}
void EX5(){
	float radius;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);
	printf("Area= %.2f",Area(radius));
}
