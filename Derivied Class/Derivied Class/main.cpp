#include <iostream>
#include <cstring>
using namespace std;
////////////// Person class Definition /////////////////
class Person {
protected: // A derived class can access protected data
    char Name[20];
public:
    Person(char* n)
    {
        strcpy(Name, n);
    }
    virtual void print() const
    {
        cout << "Person: " << Name << endl;
    }
};

///////////// Student class Definition //////////////

class Student : public Person {
private:
    int units;
public:
    // Student constructor gets name from Person class
    Student(char* n, int u) : Person(n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student: " << Name << " Units: " << units << endl;
    }
};

//////////// Teacher class Definition ////////////////
class Teacher : public Person {
private:
    int numberOfStudents;
    int numberOfClasses;
public:
    // Teacher constructor gets 'name' from the Person class
    Teacher(char* n, int s, int c) : Person(n)
    {
        numberOfStudents = s;
        numberOfClasses = c;
    }
    virtual void print() const
    {
        cout << "Teacher: " << Name
        << " Students: " << numberOfStudents
        << " Classes: " << numberOfClasses << endl;
    }
};
//////////// Employee class Definition ////////////////
class Employee : public Person {
private:
    int EmpNo; // Employee number
    double Hours;
    double PayRate;
public:
    // Teacher constructor gets 'name' from the Person class
    Employee(char* n, int eno, double hours, double pay_rate) : Person(n)
    {
        EmpNo = eno;
        Hours = hours;
        PayRate = pay_rate;
    }
    virtual void print() const
    {
        cout << "Employee: " << Name
        << "\tPay: " << Hours * PayRate
        << endl;
    }
};
/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
    // create objects from several different types of classes
    Student s1("Joe Williams", 12);
    Student s2("Mary Smith ", 9);
    Student s3("Tam Nguyen ", 10);
    Student s4("Jose Chavez ", 11);
    Teacher t1("Dan McElroy ", 28, 3);
    Teacher t3("Fred Jones ", 18, 2);
    // add 3 employees
    Employee e1("Adam ", 1, 10, 35.0);
    Employee e2("George", 2, 18, 50.0);
    Employee e3("Tim ", 3, 24, 70.0);
    // Create an array of pointers to different people
    Person *List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &e1, &e2, &e3 };
    int SizeOfList = sizeof(List) / sizeof(Person*);
    for (int i = 0; i<SizeOfList; i++)
    {
        // call the appropriate virtual print routine based
        
        // on the type of object being pointed to
        
        List[i]->print();
    }
    return 0;
}

