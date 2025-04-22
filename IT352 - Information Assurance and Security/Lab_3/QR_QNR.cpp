#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void computeQR_QNR(int n) {
    set<int> QR; 
    set<int> ZnStar;

    for (int i = 1; i < n; ++i) {
        if (gcd(i, n) == 1) { 
            ZnStar.insert(i);
        }
    }

    for (int x : ZnStar) {
        int res = (x * x) % n;
        QR.insert(res);
    }

    cout << "Quadratic Residues (QR) modulo " << n << ": ";
    for (int q : QR) {
        cout << q << " ";
    }
    cout << endl;

    set<int> QNR;
    for (int num : ZnStar) {
        if (QR.find(num) == QR.end()) { 
            QNR.insert(num);
        }
    }

    cout << "Quadratic Non-Residues (QNR) modulo " << n << ": ";
    for (int q : QNR) {
        cout << q << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number (n): ";
    cin >> n;

    if (n <= 1) {
        cout << "Invalid input. n should be greater than 1.\n";
        return 1;
    }
    
    computeQR_QNR(n);
    return 0;
}
