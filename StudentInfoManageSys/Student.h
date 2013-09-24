//defines the student struct and operation functions

#ifndef STUDENT_HEAD
#define STUDENT_HEAD

typedef struct node //defines the student struct
{
	int num; //student number
	char name[15]; //name
	char sex[9];
	int age;
	int english; //English grade
	int math;
	int computer;
	int average; //average garade
	struct node* next; //list pointer area 
}student_info;

//student info list
extern student_info* student_list; //extern a global variable

//initialization function declaration
//initialize student info list
void init_student_info_list();
//check if student info list is empty
int student_list_empty();

//operation function declaration
//add student info
int add_student_info();
//delete student info by student number
int delete_student_info(int num);
//modify student info by student number
int modify_student_info(int num);
//search student info by student number
student_info* search_student_info(int num);
//display average grades of all students
void display_average();
//display student information
void display_student_info();
//save student info to file
int save_file();
//read student info from file
int read_file();

#endif
