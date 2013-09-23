#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct DataType{//defines all the information;
	char number[20]; //student number;
	char name[20]; //name;
	char birthday[20]; //birthday;
	char sex[1];//sex;
	char class_num[20];//class;
	char telephone[12];//phone number;
	char dom[10];//dormitory
	char address[20];//address
};

struct student{//defines student informaion;
	DataType data;
	student* next;
};

class txl{
private:
	student* head;//head pointer
	student* currptr;//current pointer

public:
	txl();
	~txl();

	void Create(); //create a new student contract;
	void Insert(); //insert student information to the contract;
	void Delete(); //delete student information from the contract;
	void WriteFile(); //save student contract to a file;
	void ReadFile(); //read student contract from a file;
	void Search(); //search a student information from contract;
	void Display(); //display student contracts;
	void Revise(); //modify student information in the contract;
	void Count(); //diisplay statitical student information;
	void Exit(); //exit from system
};

txl::txl(){//constructor
	head = currptr = NULL;
};

txl::~txl(){//deconstructor
	student* temp = head;
	
	while(temp){
		delete temp;
	}
}

//create a new student contract
//argument: none
//return value: none
void txl::Create(){
	cout<<"How many students do you want to have in the student contract system: ";
		
	int n;
	char mf[1];
	
	cin>>n;
	cout<<"\n";
	cout<<"******Enter student information******\n"<<endl;

	//enter student information
	for(int i = 1; i <= n; i++){
		currptr = new student;

		cout<<"Please enter the number of student "<<i;
		cin>>currptr->data.number;
		cout<<"Please enter the name of student "<<i;
		cin>>currptr->data.name;
		cout<<"Please enter the birthday of student "<<i;
		cin>>currptr->data.birthday;
		cout<<"Please enter sex of student "<<i;
		cin>>currptr->data.sex;

		cin>>*mf;
		while((*mf) != 'm' && (*mf) != 'f'){//adjust the input format
			cout<<"Input format unaccepted, please enter f or m!"<<endl;
			cout<<"Please enter sex of student "<<i;
			cin>>*mf;
		}

		if((*mf) == 'm' || (*mf) == 'f'){
			*(currptr->data.sex) == (*mf);
		}

		cout<<"Please enter the class number of student "<<i;
		cin>>currptr->data.class_num;
		cout<<"Please enter the telephone of student "<<i;
		cin>>currptr->data.telephone;
		cout<<"Please enter the dormitory of student "<<i;
		cin>>currptr->data.dom;
		cout<<"Please enter the address of student "<<i;
		cin>>currptr->data.address;

		currptr->next = head;//insert into head;
		head = currptr;
	}

	cout<<"Informations of "<<n<<" students have been entered."<<endl;
}

//insert student information to student contract
//function: insert into the student contract list and ask user if they want to save
//argument: none
//return value: none
void txl::Insert(){
	char mf[1];
	int k;//records the insertion postition;
	int n = 0;//records the length of list;

	cout<<"Where do you want to insert: ";
	cin>>k;
	student* p = head;
	student* q = NULL;
	student* t = head;

	while(t){
		t = t->next;
		n++;
	}

	if(k > n + 1 || n < 1){//the position user wnats to insert does not exist;
		cout<<"Ilegal position!"<<endl;
	}else{
		currptr = new student;

		cout<<"Please enter the information of student you want to insert!"<<endl;
		cout<<"Please enter student number: ";
		cin>>currptr->data.number;
		cout<<"Please enter name: ";
		cin>>currptr->data.name;
		cout<<"Please enter birthday: ";
		cin>>currptr->data.birthday;
		cout<<"Please enter gender: ";
		cin>>*mf;

		while((*mf) != 'm' || (*mf) != 'f'){
			cout<<"Invalid format, please enter m or f."<<endl;
			cout<<"Please enter gender: ";
			cin>>(*mf);
		}

		if((*mf) == 'm' || (*mf) == 'f'){
			*(currptr->data.sex) = (*mf);
		}

		cout<<"Please enter class: ";
		cin>>currptr->data.class_num;
		cout<<"Please enter the telephone: ";
		cin>>currptr->data.telephone;
		cout<<"Please enter dormitory: ";
		cin>>currptr->data.dom;
		cout<<"Please enter address: ";
		cin>>currptr->data.address;

		if(k == 1){//first element, so establish list
			currptr->next = head;
			head = currptr;
		}else{
			for(int i = 1; i < k; i++){
				q = p;
				p = p->next;
			}

			q->next = currptr;
			currptr->next = p;
		}
	}
}

//delete student information from student contract
//function: delete nodes
//argument: none
//return value: none
void txl::Delete(){
	if(head != NULL){//when the list exists, delete
		int k;//records the current postion
		int n = 0;//records the number of nodes
		char ch;//save the way of deletion that user choose

		student* cu = head;
		student* p = head;
		student* q = head->next;
		student* t = head;

		cout<<"You can delete student in the two ways: "<<endl;
		cout<<"1.Delete by student number."<<endl;
		cout<<"2.Delete by student name."<<endl;
		cout<<"Please choose the one of the ways of deletion(1 or 2).";
		cin>>ch;

		//determine if input is valid
		while(ch != '1' && ch != '2'){
			cout<<endl;
			cout<<"Invalid input, please enter again(1 or 2): ";
			cin>>ch;
		}

		if(ch == '1'){
			char num[20];//record the student number that user enter
			cout<<"Please enter student number: ";
			cin>>num;

			while(cu != NULL){
				n++;//n is the index of target node

				if(strcmp(cu->data.number, num) == 0){//determine if current student is the one user wants
					break;
				}

				cu = cu->next;
			}

			if(cu == NULL){
				cout<<"This student number does not exist."<<endl;
			}else{
				k = n;
				if(k == 1){
					head = head->next;
				}else{
					
					//after the for loop, p points to the node right before the target node
					//q points to the target node
					for(int i = 1; i < k - 1; i++){
						p = q;
						q = q->next;
					}

					if(q == NULL){
						p = NULL;
					}else{
						p->next = q->next;
					}

				cout<<"Deletion succeeded!"<<endl;
				}
			}
		}else{
			int n = 0;
			char nam[20];

			cout<<"Please enter student name: ";
			cin>>nam;

			while(cu != NULL){
				n++;

				if(strcmp(cu->data.name, nam) == 0){//determine if the current name is the one user wants
					break;
				}

				cu = cu->next;
			}

			if(cu == NULL){
				cout<<"This name does not exist."<<endl;
			}else{
				k = n;

				if(k == 1){
					head = head->next;
				}else{
					for(int i = 1; i < k - 1; i++){
						p = q;
						q = q->next;
					}

					if(q == NULL){
						p = NULL;
					}else{
						p->next = q->next;
					}
				}

			cout<<"Deletion succeeded!"<<endl;
			}
		}
	}
}

//search for student information in the student contract list
//function: search student through name or number
//argument: none
//return value: none
void txl::Search(){
	cout<<"You can search a student in the following ways: "<<endl;
	cout<<"1.Search by student number."<<endl;
	cout<<"2.Search by student name."<<endl;
	cout<<"In which way do you want to search(1 or 2): ";
	
	char ch;
	cin>>ch;
	cout<<"Please enter the information you would like to search: ";

	while(ch != '1' && ch != '2'){
		cout<<endl;
		cout<<"Invalid operation, please enter again: ";
		cin>>ch;
	}

	student* cu = head;

	if(ch == '1'){//search by student number;
		char num[20];
		cin>>num;

		while(cu != NULL){
			if(strcmp(cu->data.name, num) == 0){
				cout<<"The information of the student you want to find is: "<<endl;
				cout<<cu->data.number<<" "
					<<cu->data.name<<" "
					<<cu->data.birthday<<" "
					<<cu->data.sex<<" "
					<<cu->data.class_num<<" "
					<<cu->data.telephone<<" "
					<<cu->data.dom<<" "
					<<cu->data.address<<endl;
				break;
			}

			cu = cu->next;
		}

		if(cu == NULL){
			cout<<"The student does not exist!"<<endl;
		}
	}else{//search through name
		char na[20];
		cin>>na;

		while(cu != NULL){
			if(strcmp(cu->data.name, na) == 0){
				cout<<"The information of the student you want to find is: "<<endl;
				cout<<cu->data.number<<" "
					<<cu->data.name<<" "
					<<cu->data.birthday<<" "
					<<cu->data.sex<<" "
					<<cu->data.class_num<<" "
					<<cu->data.telephone<<" "
					<<cu->data.dom<<" "
					<<cu->data.address<<endl;
				break;
			}

			cu = cu->next;
		}

		if(cu == NULL){//the student does not exist
			cout<<"The student does not exist!"<<endl;
		}
	}
}


//display all the information of students
//function: export everything of the student contract list
//argument: none
//return value: none
void txl::Display(){
	if(head == NULL){
		cout<<"There is nothing in the student contract list!"<<endl;
	}else{
		student* k = head;
		cout<<setiosflags(ios::left)<<setw(10)<<"Student Number"
			<<setiosflags(ios::left)<<setw(10)<<"Student Name"
			<<setiosflags(ios::left)<<setw(10)<<"Student Birthday"
			<<setiosflags(ios::left)<<setw(6)<<"Student Gender"
			<<setiosflags(ios::left)<<setw(10)<<"Student Class"
			<<setiosflags(ios::left)<<setw(15)<<"Student Telephone Number"
			<<setiosflags(ios::left)<<setw(6)<<"Student Dormitory"
			<<setiosflags(ios::left)<<setw(10)<<"Student Address"<<endl;

		while(k){
			cout<<setiosflags(ios::left)<<setw(10)<<k->data.number
				<<setiosflags(ios::left)<<setw(10)<<k->data.name
				<<setiosflags(ios::left)<<setw(10)<<k->data.birthday
				<<setiosflags(ios::left)<<setw(6)<<k->data.sex
				<<setiosflags(ios::left)<<setw(10)<<k->data.class_num
				<<setiosflags(ios::left)<<setw(15)<<k->data.telephone
				<<setiosflags(ios::left)<<setw(6)<<k->data.dom
				<<setiosflags(ios::left)<<setw(10)<<k->data.address<<endl;

			k = k->next;
		}

		cout<<endl;
	}
}


//modify student information
//function: modify student information
//argument:none
//return value:none
void txl::Revise(){
	if(head != NULL){//delete when the student contract list exists
		char mf[1];
		student* cu = head;
		student* p = head;
		student* q = head->next;
		student* t = head;

		cout<<"You can modify through the two ways:"<<endl;
		cout<<"1.Modify by student number."<<endl;
		cout<<"2.Modify by student name."<<endl;
		cout<<"Please choose a way to modify the infomation(1 or 2):";

		char ch;
		cin>>ch;

		while(ch != '1' && ch != '2'){
			cout<<endl;
			cout<<"Invalid operation, please enter again: ";
			cin>>ch;
		}

		if(ch == '1'){
			char num[20];
			cout<<"Please enter the number: ";
			cin>>num;

			while(cu != NULL){
				if(strcmp(cu->data.number, num) == 0){
					break;
				} 

				cu = cu->next;
			}

			if(cu == NULL){
				cout<<"The student number does not exist!"<<endl;
			}else{
				cout<<"Please enter the informaion you want to modiify!"<<endl;
				cout<<"Please enter student number: ";
				cin>>cu->data.number;
				cout<<"Please enter student name: ";
				cin>>cu->data.name;
				cout<<"Please enter student birthday: ";
				cin>>cu->data.birthday;
				cout<<"Please enter student gender: ";
				cin>>(*mf);

				while((*mf) != 'm' && (*mf) != 'f'){
					cout<<"Invalid input, please enter m or f!"<<endl;
					cout<<"Please enter student gender: ";
					cin>>(*mf);
				}

				if((*mf) == 'm' || (*mf) == 'f'){
					*(cu->data.sex) = (*mf);
				}

				cout<<"Please enter student class: ";
				cin>>cu->data.class_num;
				cout<<"Please enter student telephone number: ";
				cin>>cu->data.telephone;
				cout<<"Please enter student dormitory: ";
				cin>>cu->data.dom;
				cout<<"Please enter student address: ";
				cin>>cu->data.address;
				cout<<"Modified Successfully!"<<endl;

			}
		}else{
			char nam[20];
			cout<<"Please enter student name: ";
			cin>>nam;

			while(cu != NULL){
				if(strcmp(cu->data.name, nam) == 0){
					break;
				}
				cu = cu->next;
			}

			if(cu == NULL){
				cout<<"This name does not exsit!"<<endl;
			}else{
				cout<<"Please enter the informaion you want to modiify!"<<endl;
				cout<<"Please enter student number: ";
				cin>>cu->data.number;
				cout<<"Please enter student name: ";
				cin>>cu->data.name;
				cout<<"Please enter student birthday: ";
				cin>>cu->data.birthday;
				cout<<"Please enter student gender: ";
				cin>>(*mf);

				while((*mf) != 'm' && (*mf) != 'f'){
					cout<<"Invalid input, please enter m or f!"<<endl;
					cout<<"Please enter student gender: ";
					cin>>(*mf);
				}

				if((*mf) == 'm' || (*mf) == 'f'){
					*(cu->data.sex) = (*mf);
				}

				cout<<"Please enter student class: ";
				cin>>cu->data.class_num;
				cout<<"Please enter student telephone number: ";
				cin>>cu->data.telephone;
				cout<<"Please enter student dormitory: ";
				cin>>cu->data.dom;
				cout<<"Please enter student address: ";
				cin>>cu->data.address;
				cout<<"Modified Successfully!"<<endl;
			}
		}
	}else{
		cout<<"Emptu list, please add information first!"<<endl;
		}
}

//count student contract information
//function:
//argument: none
//return value: none
void txl::Count(){
	cout<<"You can count in the following ways(1 or 2): ";
	cout<<"1.Count by gender."<<endl;
	cout<<"2.Count by class."<<endl;

	char ch;
	cin>>ch;

	while(ch != '1' && ch != '2'){
		cout<<endl;
		cout<<"Invalid operation, please enter again: ";
		cin>>ch;
	}

	student* cu = head;

	if(ch == '1'){
		cout<<"The gneder you want to count is(m or f): ";

		char sexs[1];
		int n = 0;

		cin>>sexs;
		if(cu != NULL){
			cout<<"The information of the student you want to find is: ";

			while(cu != NULL){
				if(strcmp(cu->data.sex, sexs) == 0){
					n++;
					cout<<cu->data.number<<" "
						<<cu->data.name<<" "
						<<cu->data.birthday<<" "
						<<cu->data.sex<<" "
						<<cu->data.class_num<<" "
						<<cu->data.telephone<<" "
						<<cu->data.dom<<" "
						<<cu->data.address<<endl;
				}

				cu = cu->next;
			}

			if(n == 0){
				cout<<"There isn't any student in the class!"<<endl;
			}else{
				cout<<"There is "<<n<<" students."<<endl;
			}
		}
	}else{
		cout<<"Please enter the class you want to count: ";
		char cls[20];
		int n = 0;
		cin>>cls;

		if(cu != NULL){
			cout<<"The information of the student you want to find:"<<endl;
			while(cu != NULL){
				if(strcmp(cu->data.class_num, cls) == 0){
					n++;
					cout<<cu->data.number<<" "
						<<cu->data.name<<" "
						<<cu->data.birthday<<" "
						<<cu->data.sex<<" "
						<<cu->data.class_num<<" "
						<<cu->data.telephone<<" "
						<<cu->data.dom<<" "
						<<cu->data.address<<endl;
				}

				cu = cu->next;
			}

			if(n == 0){
				cout<<"There isn't any student in the class."<<endl;
			}else{
				cout<<"There is "<<n<<" students in the class."<<endl;
			}
		}
	}
}


//write information to a file
//function: save every node in the list to a file
//argument: one node of the list
//return value: none
void txl::WriteFile(){
	student* s = head;

	ofstream fop;
	fop.open("contract.dat", ios::binary|ios::trunc); //open file in binary, overide origin file and save deleted informaion

	if(!fop){
		cout<<"Can not open contract.dat!"<<endl;
		abort();
	}

	char Y_N;
	cout<<"Do you need to save changes to  a file(Y/N):";
	cin>>Y_N;

	while(Y_N != 'Y' && Y_N != 'y' && Y_N != 'N' && Y_N != 'n'){
		cout<<"Please enter 'Y' or 'N'!";
		cin>>Y_N;
	}

	if(Y_N == 'Y' || Y_N == 'y'){
		while(s){
			while(fop.write((char *)&s->data, sizeof(s->data))){
				s = s->next;
				flush(cout);
			}
		}
		cout<<"Saved Successfully!"<<endl;
	}
	fop.close();
}

//read information from a file
//function: read information from a file and make list
//argument:none
//return value: none
void txl::ReadFile(){
	currptr = new student;
	ifstream fip("contract.dat", ios::in|ios::binary);
	
	while(fip.read((char *)&currptr->data, sizeof(currptr->data))){
		currptr->next = head;
		head = currptr;
		currptr = new student;
	}
	
	fip.close();
	delete currptr;
}


//save and exit
//function: exit the system'
//argument:none;
//return value: none
void txl::Exit(){
	WriteFile();
	cout<<"Thank you!"<<endl;
	exit(1);
}


//main.cpp
int main(){
	//system("color 3F");
	cout<<"\n";
	cout<<"***************Welcome!**************"<<endl;
	cout<<"*****Following function included*****"<<endl;
	cout<<"*                                   *"<<endl;
	cout<<"1.Enter student information"<<endl;
	cout<<"2.Insert student information"<<endl;
	cout<<"3.Delete student information"<<endl;
	//cout<<"*                                   *"<<endl;
	cout<<"4.Search student information"<<endl;
	cout<<"5.Display student information"<<endl;
	cout<<"6.Modify student information"<<endl;
	//cout<<"*                                   *"<<endl;
	cout<<"7.Count student information"<<endl;
	cout<<"8.Save information"<<endl;
	cout<<"Please select 1--8 operations"<<endl;
	//cout<<"                                    *"<<endl;
	cout<<"*************************************"<<endl;

	char ch;
	txl t;
	t.ReadFile();
	cout<<"File has been readed successfully!"<<endl<<endl;
	do{
		cout<<"**********Student Information System**********"<<endl;
		cout<<"***************Welcome!**************"<<endl;
		cout<<"*****Following function included*****"<<endl;
		cout<<"*                                   *"<<endl;
		cout<<"1.Enter student information"<<endl;
		cout<<"2.Insert student information"<<endl;
		cout<<"3.Delete student information"<<endl;
		//cout<<"*                                   *"<<endl;
		cout<<"4.Search student information"<<endl;
		cout<<"5.Display student information"<<endl;
		cout<<"6.Modify student information"<<endl;
		//cout<<"*                                   *"<<endl;
		cout<<"7.Count student information"<<endl;
		cout<<"8.Save information"<<endl;
		cout<<"Please select 1--8 operations."<<endl;
		//cout<<"                                    *"<<endl;
		cout<<"*************************************"<<endl;

		cin>>ch;

		while(ch > '8' || ch < '1'){
			cout<<"Invalid operation, please enter again: ";
			cin>>ch;
		}

		switch(ch){
		case '1':
			t.Create();
			break;
		case '2':
			t.Insert();
			break;
		case '3':
			t.Delete();
			break;
		case '4':
			t.Search();
			break;
		case '5':
			t.Display();
			break;
		case '6':
			t.Revise();
			break;
		case '7':
			t.Count();
			break;
		case '8':
			t.Exit();
			break;
		}
	}while(1);

	return 0;
}

		
	

//remaining problem: Delete() function, the relation among p, q, k, and n;
//ios::binary|ios::trunc, contract.bat;
//system("color 3F");


			

	










		












		


