#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    
    Person() : name("Unknown"), age(0), address("Unknown") {}

    
    void setInfo(const string& newName, int newAge, const string& newAddress) {
        name = newName;
        age = newAge;
        address = newAddress;
    }

    
    void getInfoFromUser() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); 

        cout << "Enter address: ";
        getline(cin, address);
    }

    
    void displayInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << endl;
    }
};

int main() {
    
    Person person;

    
    cout << "Enter information for the person:\n";
    person.getInfoFromUser();

    
    cout << "\nPerson Information:\n";
    person.displayInfo();

    return 0;
}
