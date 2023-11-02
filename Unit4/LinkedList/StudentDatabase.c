
#include "linkedlist.h"


int main(void){
	unsigned char option[40];

	while(1){
		printf("====================================\n");
		printf("Choose One of the Following Options\n");
		printf(
		"1: Add Student\n"
		"2:Delete Student\n"
		"3:View All Students\n"
		"4:Delete All Students\n"
		"5:Find Nth Student\n"
		"6:Find Number of Student\n"
		"7:Find Nth Student opposite\n"
		"8:Find the middle Student\n");
		gets(option);
		printf("====================================\n");
		switch(atoi(option)){
			case 1:
				Add_Student();
				break;
			case 2:
				Delete_Student();
				break;
			case 3:
				Show_all();
				break;
			case 4:
				Delete_all();
				break;
			case 5:
				Get_Student();
				break;
			case 6:
				Get_count();
				break;
			case 7:
				Get_LastStudent();
				break;
			case 8:
				Get_MiddleStudent();
				break;
			default:
				printf("Wrong option\n");
				break;
		}
		
	}
	
	return 0;
}