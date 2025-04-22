#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    
    void display() const {
        if (imaginary >= 0)
            std::cout << real << " + " << imaginary << "i";
        else
            std::cout << real << " - " << -imaginary << "i";
    }
};

int main() {
    Complex num1, num2;
    double real, imaginary;

    
    std::cout << "Enter real and imaginary parts of first complex number: ";
    std::cin >> real >> imaginary;
    num1 = Complex(real, imaginary);

    
    std::cout << "Enter real and imaginary parts of second complex number: ";
    std::cin >> real >> imaginary;
    num2 = Complex(real, imaginary);

    
    Complex sum = num1 + num2;
    std::cout << "Sum: ";
    sum.display();
    std::cout << std::endl;

    
    Complex diff = num1 - num2;
    std::cout << "Difference: ";
    diff.display();
    std::cout << std::endl;

    return 0;
}
