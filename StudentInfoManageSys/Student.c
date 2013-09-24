//implementations of the functions defined in Student.h

#include "Student.h"
#include <stdio.h>//standard input and output 
#include <string.h>//string operations functions
#include <malloc.h>//dynamic memory allocation funtions

//initialize student info list
void init_student_info_list(){
	//student info list head node
	student_list = (student_info*)malloc(sizeof(student_info));
	student_list->next = NULL;
}

//check if student info list is empty
int student_list_empty(){
	return student_list->next == NULL;//any value except 0 is regarded as true
}

//add student info to student info list
int add_student_info(){
	student_info *pstu = (student_info*)malloc(sizeof(student_info));
	if(pstu == NULL){
		printf("Memory Allocation Failed!\n");
		return 0;
	}

	printf("Please enter the information of the student:\n");
	printf("Please enter student number: ");
	scanf("%d", &(pstu->num));

	//check to see if the student number entered exists
	if(search_student_info(pstu->num) != NULL){
		 printf("This student number has already exists in the student information list.\n");
		 return 0;
	}

	printf("Please enter name: ");
	scanf("%s", &(pstu->name));
	printf("Please enter sex: ");
	scanf("%s", &(pstu->sex));
	printf("Please enter English grade: ");
	scanf("%s", &(pstu->english));
	printf("Please enter Math grade: ");
	scanf("%s", &(pstu->math));
	printf("Please enter Computer grade: ");
	scanf("%s", &(pstu->computer));

	pstu->average = (pstu->english + pstu->math + pstu->computer) / 3;

	//insert to the student info list from head
	pstu->next = student_list->next;
	student_list->next = pstu;
	return 1;
}
	
//delete student info by student number
int delete_student_info(int num){
	student_info* pstu;
	student_info* qstu;

	if(search_student_info(num) == NULL){
		printf("This student number dose not exist.\n");
		return 0;
	}

	pstu = student_list->next;//first element of the student info list
	qstu = student_list;
		
	while(pstu->num != num){
		qstu = pstu;
		pstu = pstu->next;
	}

	qstu->next = pstu->next;

	free(pstu);
	return 1;
}

//modify student info by student number
int modify_student_info(int num){
	int choice;
	student_info* pstu = search_student_info(num);
	if(pstu == NULL){
		printf("There does not exist a student whose number is %d.\n", num);
		return 0;
	}

	printf("1.Name 2.Sex 3.Age 4.English Grade 5.Math Grade 6.Computer Grade.\n");
	printf("Please choose the information you want to modify: ");
	scanf("%d", &choice);

	switch(choice){
	case 1:
		printf("Please enter a new name: ");
		scanf("%s", &(pstu->name));
		break;
	case 2:
		printf("Please enter a new sex: ");
		scanf("%s", &(pstu->sex));
		break;
	case 3:
		printf("Please enter the age: ");
		scanf("%d", &(pstu->age));
		break;
	case 4:
		printf("Please enter new English grade: ");
		scanf("%d", &(pstu->english));
		break;
	case 5:
		printf("Please enter new Math grade: ");
		scanf("%d", &(pstu->math));
		break;
	case 6:
		printf("Please enter new Computer grade: ");
		scanf("%d", &(pstu->computer));
		break;
	default:
		printf("Please operate following the instructions.\n");
	}

	return 1;
}

//search student info by student number
student_info* search_student_info(int num){
	student_info* pstu;
	pstu = student_list->next;//pstu now points to the first element of the student info list

	while(pstu && pstu->num != num){
		pstu = pstu->next;
	}

	return pstu;
}

//display the average grade of every student
void display_average(){
	student_info* pstu;
	pstu = student_list->next;
	while(pstu){
		printf("The grade of the student whose number is %d and name is %s: %d\n", pstu->num, pstu->name, pstu->average);
		pstu = pstu->next;
	}
}

//display all the student information
void display_student_info(){
	student_info* pstu;
	pstu = student_list->next;//pstu now points to the first element of the student info list
	
	printf("All the Students Information:\n");
	printf("Number\tName\tSex\tAge\tEnglish\tMath\tComputer\tAverage.\n");
	
	while(pstu){
		printf("%d\t", pstu->num);
		printf("%s\t", pstu->name);
		printf("%s\t", pstu->sex);
		printf("%d  \t", pstu->age);
		printf("%d   \t", pstu->english);
		printf("%d  \t", pstu->math);
		printf("%d   \t", pstu->computer);
		printf("%d\n", pstu->average);
		
		pstu = pstu->next;
	}
}

//save student information to file
int save_file(){
	FILE* pfile;
	student_info* pstu;

	pfile = fopen("student.txt", "w");
	if(pfile == NULL){
		printf("Failed to Open a File!\n");
		return 0;
	}

	while(pstu){
		fprintf(pfile, "%5d%15s%9s%3d%4d%4d%4d%4d%4d", pstu->num, pstu->name, pstu->sex, pstu->age, pstu->english, pstu->math, pstu->computer, pstu->average);
		pstu = pstu->next;
	}

	fclose(pfile);
	return 1;
}

//read student info from file
int read_file(){
	FILE* pfile;
	student_info* pstu;
	pfile = fopen("student.txt", "r");

	if(pfile == NULL){
		printf("Failed to Open File!\n");
		return 0;
	}

	while(!feof(pfile)){
		pstu = (student_info*)malloc(sizeof(student_info));
		fscanf(pfile, "%5d%15s%9s%3d%4d%4d%4d%4d", &(pstu->num), &(pstu->name), &(pstu->sex), &(pstu->age), &(pstu->english), &(pstu->math), &(pstu->computer));
		pstu->average = (pstu->english + pstu->math + pstu->computer) / 3;
		
		//insert to student info list from head
		pstu->next = student_list->next;
		student_list->next = pstu;
	}

	fclose(pfile);
	return 1;
}








