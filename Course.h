#pragma once
#include <string>
#include "Student.h"
#include <iostream>
using namespace std;
class Student;

class Course {
private:
	string name;
	int number_co;
	Student** arrstud;
	int number_stud;
	int* arrg;
public:
	Course();
	Course(string, int);
	~Course();
	void operator=(Course&);
	bool operator==(Course);
	bool operator==(int);
	void operator+=(Student&);
	void grade(string, int);
	friend ostream& operator<<(ostream&, Course);
	friend istream& operator>>(istream&, Course);
};