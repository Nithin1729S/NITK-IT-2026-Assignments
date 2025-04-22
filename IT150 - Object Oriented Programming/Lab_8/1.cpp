#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for Student
class Student {
protected:
    string name;
    int age;

public:
    Student(string name, int age) : name(name), age(age) {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

// Derived classes for different departments
class EngineeringStudent : public Student {
private:
    string specialization;

public:
    EngineeringStudent(string name, int age, string specialization) : Student(name, age), specialization(specialization) {}

    void display() const override {
        cout << "Engineering Student - ";
        Student::display();
        cout << ", Specialization: " << specialization;
    }
};

class ManagementStudent : public Student {
private:
    string major;

public:
    ManagementStudent(string name, int age, string major) : Student(name, age), major(major) {}

    void display() const override {
        cout << "Management Student - ";
        Student::display();
        cout << ", Major: " << major;
    }
};

class ArtsStudent : public Student {
private:
    string areaOfStudy;

public:
    ArtsStudent(string name, int age, string areaOfStudy) : Student(name, age), areaOfStudy(areaOfStudy) {}

    void display() const override {
        cout << "Arts Student - ";
        Student::display();
        cout << ", Area of Study: " << areaOfStudy;
    }
};

// Function to create student objects based on user input
Student* createStudent() {
    string name, department;
    int age;
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student age: ";
    cin >> age;
    cin.ignore(); // Clear input buffer
    cout << "Enter department (Engineering/Management/Arts): ";
    getline(cin, department);

    if (department == "Engineering") {
        string specialization;
        cout << "Enter specialization: ";
        getline(cin, specialization);
        return new EngineeringStudent(name, age, specialization);
    } else if (department == "Management") {
        string major;
        cout << "Enter major: ";
        getline(cin, major);
        return new ManagementStudent(name, age, major);
    } else if (department == "Arts") {
        string areaOfStudy;
        cout << "Enter area of study: ";
        getline(cin, areaOfStudy);
        return new ArtsStudent(name, age, areaOfStudy);
    } else {
        cout << "Invalid department!" << endl;
        return nullptr;
    }
}

// Function to demonstrate polymorphism
void displayStudent(const Student& student) {
    student.display();
    cout << endl;
}

int main() {
    vector<Student*> students;

    // Input student details from user
    cout << "Enter details for 3 students:" << endl;
    for (int i = 0; i < 3; ++i) {
        Student* student = createStudent();
        if (student != nullptr) {
            students.push_back(student);
        }
    }

    // Displaying information of all students
    cout << "\nStudent Information:" << endl;
    for (const auto& student : students) {
        displayStudent(*student);
    }

    // Clean up memory
    for (auto& student : students) {
        delete student;
    }

    return 0;
}
