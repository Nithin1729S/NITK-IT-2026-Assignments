#include <iostream>

using namespace std;


double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Division by zero exception";
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int numerator, denominator;
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;

    try {
        double result = divide(numerator, denominator);
        cout << "Result of division: " << result << endl;
    } catch (const char* exception) {
        cerr << "Exception caught: " << exception << endl;
    }

    return 0;
}


