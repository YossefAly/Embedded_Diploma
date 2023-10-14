/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: ALY
 */
#include "stdio.h"

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
	float matrix1[2][2];
	float matrix2[2][2];
	float matrix3[2][2];
	int i;
	int j;
	printf("Enter The Elements of first matrix\n");
	fflush(stdout);
	printf("Enter a11 : ");
	fflush(stdout);
	scanf("%f",&matrix1[0][0]);
	fflush(stdin);
	printf("Enter a12 : ");
	fflush(stdout);
	scanf("%f",&matrix1[0][1]);
	fflush(stdin);
	printf("Enter a21 : ");
	fflush(stdout);
	scanf("%f",&matrix1[1][0]);
	fflush(stdin);
	printf("Enter a22 : ");
	fflush(stdout);
	scanf("%f",&matrix1[1][1]);
	fflush(stdin);
	printf("Enter The Elements of Second matrix\n");
	fflush(stdout);
	printf("Enter b11 : ");
	fflush(stdout);
	scanf("%f",&matrix2[0][0]);
	fflush(stdin);
	printf("Enter b12 : ");
	fflush(stdout);
	scanf("%f",&matrix2[0][1]);
	fflush(stdin);
	printf("Enter b21 : ");
	fflush(stdout);
	scanf("%f",&matrix2[1][0]);
	fflush(stdin);
	printf("Enter b22 : ");
	fflush(stdout);
	scanf("%f",&matrix2[1][1]);

	for(i=0;i<2;i++){

		for(j=0;j<2;j++){
			matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	fflush(stdout);
	printf("Sum of Matrix\n");
	fflush(stdout);
	printf("%.1f	%.1f\n",matrix3[0][0],matrix3[0][1]);
	printf("%.1f	%.1f\n",matrix3[1][0],matrix3[1][1]);

}
void EX2(){
	int number;
	int index;
	float sum=0;
	printf("Enter The numbers of data :");
	fflush(stdout);
	scanf("%d",&number);
	float array[number];
	for(index=0;index<number;index++){
		printf("Enter number: ");
		fflush(stdout);
		scanf("%f",&array[index]);
	}
	for(index=0;index<number;index++){
		sum+=array[index];
	}
	printf("Average = %.2f",sum/number);
}
void EX3(){
	int i;
	int j;
	int indexi;
	int indexj;
	printf("Enter rows and columns of matrix: ");
	fflush(stdout);
	scanf("%d%d",&i,&j);
	int matrix[i][j];
	for(indexi=0;indexi<i;indexi++){
		for(indexj=0;indexj<j;indexj++){
			printf("Enter elements a%d%d: ",indexi+1,indexj+1);
			fflush(stdout);
			scanf("%d",&matrix[indexi][indexj]);}
	}
	printf("Entered Matrix \n");
	for(indexi=0;indexi<i;indexi++){
		printf("\n");
		for(indexj=0;indexj<j;indexj++)
				printf("%d\t",matrix[indexi][indexj]);
	}
	for(indexi=0;indexi<i;indexi++){
		for(indexj=1;indexj<j;indexj++)
			if(indexi==indexj){
				continue;
			}
			else{
				matrix[indexi][indexj]=matrix[indexi][indexj]+matrix[indexj][indexi];
				matrix[indexj][indexi]=matrix[indexi][indexj]-matrix[indexj][indexi];
				matrix[indexi][indexj]=matrix[indexi][indexj]-matrix[indexj][indexi];
			}
	}
	printf("\nTransposed Matrix \n");
	i=i+j;
	j=i-j;
	i=i-j;
	for(indexi=0;indexi<i;indexi++){
		printf("\n");
		for(indexj=0;indexj<j;indexj++)
				printf("%d\t",matrix[indexi][indexj]);
	}
}
void EX4(){
	int number;
	int newnumber;
	int newnumberindex;
	int index;
	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d",&number);
	int array[number];
	printf("\n");
	fflush(stdout);
	for(index=0;index<number;index++){
		scanf("%d",&array[index]);
	}
	printf("Enter the Element to be inserted : ");
	fflush(stdout);
	scanf("%d",&newnumber);
	printf("Enter the location :");
	fflush(stdout);
	scanf("%d",&newnumberindex);
	for(index=0;index<number;index++){
		if(index==newnumberindex-1){
			array[index]=array[index]+newnumber;
			newnumber=array[index]-newnumber;
			array[index]=array[index]-newnumber;
			newnumberindex++;
		}
	}
	array[number]=newnumber;
	for(index=0;index<number+1;index++){
		printf("%d ",array[index]);
	}
}
void EX5(){
	int number;
	int index;
	int location;
	int find;
	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d",&number);
	int array[number];
	printf("\n");
	fflush(stdout);
	for(index=0;index<number;index++){
		scanf("%d",&array[index]);
	}
	printf("Enter the element to be searched : ");
	fflush(stdout);
	scanf("%d",&find);
	for(index=0;index<number;index++){
		if(find==array[index]){
			location=index+1;
			printf("Number found at location %d",location);
			break;
		}
	}

}
