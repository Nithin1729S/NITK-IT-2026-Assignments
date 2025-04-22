#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool is_QR(long long a, long long p) {
    if (a == 0) return true; // 0 is always a QR
    long long result = binpow(a, (p - 1) / 2, p);
    return result == 1;
}

void find_QR_QNR(long long p) {
    std::vector<long long> QR, QNR;

    for (long long a = 1; a < p; ++a) {
        if (is_QR(a, p))
            QR.push_back(a);
        else
            QNR.push_back(a);
    }
    
    // Print QR
    std::cout << "Quadratic Residues (QR) in Z" << p << "*: ";
    for (auto q : QR) std::cout << q << " ";
    std::cout << "\n";
    
    // Print QNR
    std::cout << "Quadratic Non-Residues (QNR) in Z" << p << "*: ";
    for (auto q : QNR) std::cout << q << " ";
    std::cout << "\n";
}

int main() {
    int n;
    cout << "Enter a number (n): ";
    cin >> n;

    if (n <= 1) {
        cout << "Invalid input. n should be greater than 1.\n";
        return 1;
    }
    
    find_QR_QNR(n);
    return 0;
}
