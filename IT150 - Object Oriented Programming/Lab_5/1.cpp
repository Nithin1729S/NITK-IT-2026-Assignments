#include <iostream>

class temp {
private:
    int count;
public:
    // Constructor
    temp() : count(5) {}

    // Overloading the unary operator ++
    void operator++() {
        count++;
    }

    // Overloading the unary operator --
    void operator--() {
        count--;
    }

    // Function to get the value of count
    int getCount() const {
        return count;
    }
};

int main() {
    temp obj;

    std::cout << "Initial count: " << obj.getCount() << std::endl;

    char choice;
    std::cout << "Do you want to increment (++), decrement (--), or exit (E)? ";
    std::cin >> choice;

    while (choice != 'E') {
        if (choice == '+') {
            ++obj; // Using overloaded ++
            std::cout << "After increment: " << obj.getCount() << std::endl;
        } else if (choice == '-') {
            --obj; // Using overloaded --
            std::cout << "After decrement: " << obj.getCount() << std::endl;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }

        std::cout << "Do you want to increment (++), decrement (--), or exit (E)? ";
        std::cin >> choice;
    }

    return 0;
}
