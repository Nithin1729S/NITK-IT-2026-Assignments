#include <iostream>
#include <string>

// Grandparent class
class Animal {
public:
    virtual void make_sound() {
        // default implementation or leave it pure virtual for an abstract class
    }
};

// Parent class inheriting from Animal
class Mammal : public Animal {
public:
    void give_birth() {
        // implementation for giving birth
    }
};

// Another parent class inheriting from Animal
class Bird : public Animal {
public:
    void lay_eggs() {
        // implementation for laying eggs
    }
};

// Child class inheriting from Mammal
class Dog : public Mammal {
public:
    void make_sound() override {
        std::cout << "Enter the sound for Dog: ";
        std::cin >> sound;
        std::cout << sound << std::endl;
    }

private:
    std::string sound;
};

// Child class inheriting from Bird
class Parrot : public Bird {
public:
    void make_sound() override {
        std::cout << "Enter the sound for Parrot: ";
        std::cin >> sound;
        std::cout << sound << std::endl;
    }

private:
    std::string sound;
};

// Grandchild class inheriting from both Dog and Parrot
class Hybrid : public Dog, public Parrot {
public:
    void make_sound() override {
        std::cout << "Enter the sound for Hybrid: ";
        std::cin >> sound;
        std::cout << sound << std::endl;
    }

private:
    std::string sound;
};

int main() {
    Hybrid hybrid;
    // Accessing methods of all classes in the hierarchy
    hybrid.make_sound();    // Accessing method from Hybrid
    hybrid.give_birth();    // Accessing method from Mammal
    hybrid.lay_eggs();      // Accessing method from Bird
    return 0;
}
