#include "Student.h"

ostream& operator<<(ostream& out, Student s)
{
    out << "Student name:" << s.name << endl;
    out << "Student id:" << s.id << endl;
    out << "Student gender:" << s.migdar << endl;
    out << "Student age:" << s.age << endl;
    if (s.numc == 0)
        out << "The student isn't registered to courses." << endl;
    else
        out << "Student is registered to " << s.numc << " courses." << endl;
    return out;// TODO: insert return statement here
}

istream& operator<<(istream& in, Student s)
{
    cout << "Enter student name:";
    in >> s.name;
    cout << "Enter student id:";
    in >> s.id;
    cout << "Enter student gender:";
    in >> s.migdar;
    cout << "Enter student age:";
    in >> s.age;
    return in;// TODO: insert return statement here
}

Student::Student()
{
    courses = NULL;
    numc = 0;
}

Student::Student(string _name, string _id, char _migdar, int _age)
{
    name = _name;
    id = _id;
    migdar = _migdar;
    age = _age;
    numc = 0;
    courses = NULL;
}

Student::~Student()
{
    if (courses)
        delete[] courses;
}

void Student::operator=(const Student s)
{
    name = s.name;
    id = s.id;
    migdar = s.migdar;
    age = s.age;
    numc = s.numc;
    courses = new Course * [numc];
    for (int i = 0; i < numc; i++)
        courses[i] = s.courses[i];
}

bool Student::operator==(const Student s)
{
    return id == s.id;
}

bool Student::operator==(string _id)
{
    return id == _id;
}

void Student::operator+=(Course& s)
{
    Course** temp = new Course * [numc + 1];
    for (int i = 0; i < numc; i++)
        temp[i] = courses[i];
    delete courses;
    temp[numc++] = &s;
    courses = temp;
}
