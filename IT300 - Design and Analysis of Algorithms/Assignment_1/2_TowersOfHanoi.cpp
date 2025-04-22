#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 0) return; 
    if (n == 1) {
        cout << a << " to " << b << endl;
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << a << " to " << b << endl;
    hanoi(n - 1, c, b, a);
}

int main() {
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
