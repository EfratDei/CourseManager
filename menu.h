#pragma once
#include "Course.h"
#include "Student.h"
 
class Menu {
private:
	Course** arrco;
	int numco;
	Student** arrstud;
	int numstud;
	void Add_Course();
	void Add_Student();
	void Reg_Student();
	void Grade_Student();
	void Print_Course();
	void Print_Student();
public:
	void Run();
	Menu();
	~Menu();
};