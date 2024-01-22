#pragma once
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;
class Course;

class Student {
private:
    string name, id;
    char migdar;
    int age;
    Course** courses;
    int numc;
public:
    Student();
    Student(string, string, char, int);
    ~Student();
    void operator=(const Student);
    bool operator==(const Student);
    bool operator==(string);
    void operator+=(Course&);
    friend ostream& operator <<(ostream&, Student);
    friend istream& operator <<(istream&, Student);
};
