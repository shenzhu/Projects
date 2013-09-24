#include "Student.h"
#include <stdlib.h>
#include <stdio.h>

void menu();

//student info list
student_info* student_list;

void menu(){
	printf("1.Check student information.\n");
	printf("2.Add student information.\n");
	printf("3.Delete student information.\n");
	printf("4.Modify student information.\n");
	printf("5.Display average grades.\n");
	printf("6.Save student information.");
	printf("0.Exit system.\n");
}

int main(){
	int choice;
	int num;
	printf("********\n");
	printf("Welcome!");
	printf("********\n");
	printf("---------------------------------\n");

	init_student_info_list();

	if(read_file()){
		printf("File has been loaded.\n");
	}else{
		printf("Failed to load file.\n");
	}

	menu();

	while(1){
		printf("Please select operation: ");
		scanf("%d", &choice);

		switch(choice){
		case 1:
			if(student_list_empty()){
				printf("Empty list, please add information first.\n");
			}else{
				display_student_info();
			}
			break;
		case 2:
			if(add_student_info()){
				printf("Student information has been added.\n");
			}else{
				printf("Failed to add student information.\n");
			}
			break;
		case 3:
			if(student_list_empty()){
				printf("Empty list, please add student information first.\n");
			}else{
				printf("Please enter the student number: ");
				scanf("%d", &num);
				if(delete_student_info(num)){
					printf("Student information has been deleted successfully.\n");
				}else{
					printf("Deletion failed.\n");
				}
			break;
		case 4:
			if(student_list_empty()){
				printf("Empty list, please add information.");
			}else{
				printf("Please enter the number: ");
				scanf("%d", &num);
				if(modify_student_info(num)){
					printf("Modified.\n");
				}else{
					printf("Failed to modify.\n");
				}
			}
			break;
		case 5:
			if(student_list_empty()){
				printf("Empty list, please add student information.\n");
			}else{
				display_average();
			}
			break;
		case 6:
			if(student_list_empty()){
				printf("Empty list, please add information.\n");
			}else{
				if(save_file()){
					printf("Student information has been saved.\n");
				}else{
					printf("Failed to save student information.\n");
				}
			}
			break;
		case 0:
			printf("Bye!\n");
			system("pause");
			exit(0);//exit is a library function, 0 stands for exit successfully, 1 stands for an unexpected exit
			break;
		default:
			printf("Wrong input, please choose operation again.\n");
			}
		}

		system("pause");
		return 0;
	}
}

	