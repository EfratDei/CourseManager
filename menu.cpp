#include "menu.h"

void Menu::Add_Course()
{
	string name;
	int id;
	cout << "Enter course name:";
	cin >> name;
	cout << "Enter course id:";
	cin >> id;
	for(int i=0;i<numco;i++)
		if (arrco[i]->operator==(id)) {
			cout<<"There's already a course with this ID."<<endl;
			return;
		}
	Course** temp = new Course * [numco + 1];
	for (int i = 0; i < numco; i++)
		temp[i] = arrco[i];
	delete arrco;
	temp[numco++] = new Course(name, id);
	arrco = temp;
}

void Menu::Add_Student()
{
	string name, id;
	int age;
	char migdar;
	cout << "Enter student name:";
	cin >> name;
	cout << "Enter student id:";
	cin >> id;
	cout << "Enter student age:";
	cin >> age;
	cout << "Enter student migdar:";
	cin >> migdar;
	for (int i = 0; i < numstud; i++)
		if (arrstud[i]->operator==(id)) {
			cout << "There's already a student with this ID." << endl;
			return;
		}
	Student** temp = new Student * [numstud + 1];
	for (int i = 0; i < numstud; i++)
		temp[i] = arrstud[i];
	delete arrstud;
	temp[numstud++] = new Student(name, id, migdar, age);
	arrstud = temp;
}

void Menu::Reg_Student()
{
	int cID;
	string sID;
	cout << "Enter course id:";
	cin >> cID;
	cout << "Enter student id:";
	cin >> sID;
	int sIndex, cIndex;
	for (cIndex = 0; cIndex < numco; cIndex++)
		if (*(arrco[cIndex]) == cID)
			break;
		else if (cIndex == numco - 1) {
			cout << "No course with such ID" << endl;
			return;
		}
	for (sIndex = 0; sIndex < numstud; sIndex++)
		if (*(arrstud[sIndex]) == sID)
			break;
		else if (sIndex == numstud - 1) {
			cout << "No student with such ID" << endl;
			return;
		}
	*(arrstud[sIndex]) += *(arrco[cIndex]);
	*(arrco[cIndex]) += *(arrstud[sIndex]);
}

void Menu::Grade_Student()
{
	int cID, grade;
	string sID;
	cout << "Enter course id:";
	cin >> cID;
	cout << "Enter student id:";
	cin >> sID;
	cout << "Enter grade:";
	cin >> grade;
	for (int i = 0; i < numco; i++)
		if (*(arrco[i]) == cID)
			for (int j = 0; j < numstud; j++) {
				if (*(arrstud[i]) == sID)
					arrco[i]->grade(sID, grade);
				else if (j == numstud - 1) {
					cout << "No student with such ID" << endl;
					return;
				}
			}
		else if (i==numco-1) {
			cout << "No course with such ID" << endl;
			return;
		}
}

void Menu::Print_Course()
{
	int cID;
	cout << "Enter course ID:";
	cin >> cID;
	for (int i = 0; i < numco; i++)
		if (*(arrco[i]) == cID)
			cout << *(arrco[i]);
		else if (i == numco - 1) {
			cout << "No course with such ID." << endl;
			return;
		}
}

void Menu::Print_Student()
{
	string sID;
	cout << "Enter student ID:";
	cin >> sID;
	for (int i = 0; i < numstud; i++)
		if (*(arrstud[i]) == sID)
			cout << *(arrstud[i]);
		else if (i == numstud - 1) {
			cout << "No student with such ID." << endl;
			return;
		}
}

void Menu::Run()
{
	while (true) {
		cout << "enter 1 for add course" << endl;
		cout << "enter 2 for add name student" << endl;
		cout << "enter 3 for register for course" << endl;
		cout << "enter 4 for grade " << endl;
		cout << "enter 5 for det course " << endl;
		cout << "enter 6 for det student" << endl;
		cout << "enter 7 for exit" << endl;
		cout << "enter you'r choice" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			Add_Course();
			break;
		case 2:
			Add_Student();
			break;
		case 3:
			Reg_Student();
			break;
		case 4:
			Grade_Student();
			break;
		case 5:
			Print_Course();
			break;
		case 6:
			Print_Student();
			break;
		case 7:
			exit(1);


		}
	}
}

Menu::Menu()
{
	arrstud = NULL;
	numco = 0;
	arrco = NULL;
	numstud = 0;
}

Menu::~Menu()
{
	if (arrstud)
		delete[] arrstud;
	if (arrco)
		delete[] arrco;
}

