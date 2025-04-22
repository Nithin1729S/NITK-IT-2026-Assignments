#include <iostream>

// Base class
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;

public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {}
    
    void display() {
        std::cout << "Base Class - Public: " << publicVar << ", Protected: " << protectedVar << ", Private: " << privateVar << std::endl;
    }
};

// Case a) Derived Class is inheriting the Base Class publicly
class DerivedPublic : public Base {
public:
    void displayDerived() {
        // Public and Protected members of Base class are accessible in the derived class
        std::cout << "Derived Public Class - Public: " << publicVar << ", Protected: " << protectedVar << std::endl;
    }
};

// Case b) Derived Class is inheriting the Base Class protectedly
class DerivedProtected : protected Base {
public:
    void displayDerived() {
        // Public and Protected members of Base class are accessible in the derived class
        std::cout << "Derived Protected Class - Public: " << publicVar << ", Protected: " << protectedVar << std::endl;
    }
};

// Case c) Derived Class is inheriting the Base Class privately
class DerivedPrivate : private Base {
public:
    void displayDerived() {
        // Public and Protected members of Base class are accessible in the derived class
        std::cout << "Derived Private Class - Public: " << publicVar << ", Protected: " << protectedVar << std::endl;
    }
};

int main() {
    // Case a) - Derived Class inheriting publicly
    DerivedPublic objA;
    objA.display();
    objA.displayDerived();

    // Case b) - Derived Class inheriting protectedly
    DerivedProtected objB;
    // objB.display();  // Error: Cannot access public member in the derived class
    objB.displayDerived();

    // Case c) - Derived Class inheriting privately
    DerivedPrivate objC;
    // objC.display();  // Error: Cannot access public member in the derived class
    // objC.displayDerived();  // Error: Cannot access public or protected members in the derived class

    return 0;
}
