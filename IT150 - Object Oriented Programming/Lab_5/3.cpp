#include <iostream>
using namespace std;


class base_class {
public:
    
    virtual void printit() {
        cout << endl << "Print from base class" << endl;
    }
}; 


class first_class : public base_class  {
public:
    void printit() override {
        cout << endl << "Print from first class" << endl;
    }
}; 


class second_class : public base_class  {
}; 


class coach_class : public base_class  {
public:
    void printit() override {
        cout << endl << "Print from coach class" << endl;
    }
}; 


class tourist_class : public coach_class  {
}; 


int main() {
    base_class base;        
    base.printit();    

    first_class first1;     
    first1.printit();    

    second_class second1;     
    second1.printit();

    coach_class coach1;     
    coach1.printit();

    tourist_class tour1;     
    tour1.printit();

    return 0;
} 
