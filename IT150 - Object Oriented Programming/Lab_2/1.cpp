#include <bits/stdc++.h>
using namespace std;

// Base class
class Person {
protected:
    string personName;

public:
    Person(const string& name) : personName(name) {}

    void displayPerson() {
        cout << "\nName: " << personName << endl;
    }
};

// Derived class 1: Employee (Single Inheritance)
class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(const string& name, int id)
        : Person(name), employeeID(id) {}

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Method inside Derived Class Employee" << endl;
    }
};

// Derived class 2: Student (Single Inheritance)
class Student : public Person {
protected:
    int studentID;

public:
    Student(const string& name, int id)
        : Person(name), studentID(id) {}

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Method inside Derived Class Student" << endl;
    }
};

// Derived class 3: StudentIntern (Multiple Inheritance)
class StudentIntern : public Employee, public Student {
public:
    StudentIntern(const string& name, int empID, int stuID)
        : Employee(name, empID), Student(name, stuID) {}

    void displayStudentIntern() {
        cout << "Methods inside Derived Class StudentIntern:" << endl;
        displayEmployee();
        displayStudent();
    }
};

// Driver code
int main() {
    string name;
    int empID, stuID;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter employee ID: ";
    cin >> empID;

    cout << "Enter student ID: ";
    cin >> stuID;

    StudentIntern SI(name, empID, stuID);
    SI.displayStudentIntern();

    return 0;
}



