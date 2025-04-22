#include<bits/stdc++.h>
using namespace std;

class MyClass {
private:
    
    int privateVar;

public:
    
    int publicVar;

    
    MyClass() : privateVar(0), publicVar(0) {}

    
    void setPrivateVar(int value) {
        privateVar = value;
    }

    
    void displayInfo() {
        cout << "Private Variable: " << privateVar << endl;
        cout << "Public Variable: " << publicVar << endl;
    }
};

int main() {
    // Creating an object of the MyClass class
    MyClass obj;

    // Accessing public member directly
    obj.publicVar = 42;

    // Accessing private member using a public member function
    obj.setPrivateVar(21);

    // Displaying information using a public member function
    obj.displayInfo();

    // Attempting to access private member directly (will result in a compilation error)
    obj.privateVar = 10;

    return 0;
}


