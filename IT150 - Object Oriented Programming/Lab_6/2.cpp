#include <iostream>
#include <vector>

using namespace std;

int main() {
    // (i) Catching all exceptions
    try {
        throw "An exception occurred!";
    } catch (...) {
        cout << "(i) Caught an exception!" << endl;
    }

    // (ii) Handling array out of bounds exception
    try {
        vector<int> arr = {1, 2, 3};
        cout << "(ii) Value at index 10: " << arr.at(10) << endl;
    } catch (const out_of_range& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    // (iii) Multiple catch statements
    try {
        throw runtime_error("A runtime error occurred!");
    } catch (const runtime_error& e) {
        cerr << "(iii) Runtime error caught: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "(iii) Exception caught: " << e.what() << endl;
    }

    // (iv) Re-throwing exceptions
    try {
        try {
            throw runtime_error("Rethrowing exception!");
        } catch (const runtime_error& e) {
            cerr << "(iv) Inner exception caught: " << e.what() << endl;
            throw; // Re-throwing the caught exception
        }
    } catch (const runtime_error& e) {
        cerr << "(iv) Outer exception caught: " << e.what() << endl;
    }

    // (v) Testing throw restrictions
    try {
        throw runtime_error("Throwing exception");
    } catch (const runtime_error& e) {
        cerr << "(v) Exception caught: " << e.what() << endl;
    }

    return 0;
}
