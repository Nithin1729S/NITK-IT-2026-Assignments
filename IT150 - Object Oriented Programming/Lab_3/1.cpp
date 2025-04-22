#include <iostream>
int addByValue(int num1, int num2);
void addByReference(int num1, int num2, int &result);

int main()
{
    int number1, number2;

    std::cout << "Enter the first number: ";
    std::cin >> number1;

    std::cout << "Enter the second number: ";
    std::cin >> number2;

    int sumByValue = addByValue(number1, number2);
    std::cout << "Sum (Pass by value): " << sumByValue << std::endl;

    int sumByReference;
    addByReference(number1, number2, sumByReference);
    std::cout << "Sum (Pass by reference): " << sumByReference << std::endl;

    return 0;
}

int addByValue(int num1, int num2)
{
    return num1 + num2;
}

void addByReference(int num1, int num2, int &result)
{
    result = num1 + num2;
}
