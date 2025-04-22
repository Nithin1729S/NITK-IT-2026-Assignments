#include <iostream>
#include <string>

class Base {
public:
    
    virtual void display() {
        std::cout << "Base class display()" << std::endl;
    }
};

class Derived : public Base {
public:
    
    void display() override {
        std::cout << "Derived class display()" << std::endl;
    }
};

int main() {
    
    Derived derivedObj;
    derivedObj.display(); 

    
    Base *basePtr = &derivedObj;
    basePtr->display(); 

    
    Base &baseRef = derivedObj;
    baseRef.display(); 

    
    std::string choice;
    std::cout << "Do you want to call the overridden function? (yes/no): ";
    std::cin >> choice;

    if (choice == "yes") {
        
        Base *userChoicePtr;
        std::cout << "Enter '1' to create a Base object or '2' to create a Derived object: ";
        int type;
        std::cin >> type;

        if (type == 1) {
            userChoicePtr = new Base();
        } else {
            userChoicePtr = new Derived();
        }

        userChoicePtr->display(); 

        delete userChoicePtr; 
    }

    return 0;
}
