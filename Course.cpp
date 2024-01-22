#include "Course.h"

ostream& operator<<(ostream& out, Course c)
{
    out << "Course name: " << c.name << endl;
    out << "Course ID: " << c.number_co << endl;
    out << "There're " << c.number_stud << " students registered to this course." << endl;
    return out;// TODO: insert return statement here
}

istream& operator>>(istream& in, Course c)
{
    cout << "Enter course name:";
    in >> c.name;
    cout << "Enter course id:";
    in >> c.number_co;
    return in;
}

Course::Course()
{
    arrstud = NULL;
    number_stud = 0;
    arrg = NULL;
}

Course::Course(string _name, int _number_co)
{
    name = _name;
    number_co = _number_co;
    number_stud = 0;
    arrstud = NULL;
    arrg = NULL;
}

Course::~Course()
{
    if (arrstud)
        delete[] arrstud;
    if (arrg)
        delete[] arrg;
}

void Course::operator=(Course& c)
{
    name = c.name;
    number_co = c.number_co;
    number_stud = c.number_stud;
    arrstud = new Student * [number_stud];
    arrg = new int[number_stud];
    for (int i = 0; i < number_stud; i++) {
        arrstud[i] = c.arrstud[i];
        arrg[i] = c.arrg[i];
    }
}

bool Course::operator==(Course c)
{
    return number_co == c.number_co;
}

bool Course::operator==(int id)
{
    return number_co==id;
}

void Course::operator+=(Student& s)
{
    Student** temp = new Student * [number_stud + 1];
    int* tempgrades = new int[number_stud + 1];
    for (int i = 0; i < number_stud; i++) {
        temp[i] = arrstud[i];
        tempgrades[i] = arrg[i];
    }
    delete arrstud;
    delete arrg;
    tempgrades[number_stud] = -1;
    temp[number_stud++] = &s;
    arrstud = temp;
    arrg = tempgrades;
}

void Course::grade(string id, int grade)
{
    for (int i = 0; i < number_stud; i++)
        if (*(arrstud[i]) == id) {
            arrg[i] = grade;
            return;
        }
        else if (i == number_stud - 1) {
            cout << "Student with id:" << id << " isn't registered to this course." << endl;
            return;
        }
}

