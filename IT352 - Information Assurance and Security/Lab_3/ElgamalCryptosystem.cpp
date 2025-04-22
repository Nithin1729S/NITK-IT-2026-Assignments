#include<bits/stdc++.h>
using namespace std;

long long powmod(long long a, long long b, long long m) {
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

int findAllPrimitiveRoots(int p) {
    vector<int> fact; //factors of phi_n
    int phi = p - 1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) fact.push_back(n);
    vector<int> primitive_roots;
    for (int res = 2; res < p; ++res) {
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= powmod(res, phi / fact[i], p) != 1;
        if (ok) primitive_roots.push_back(res);
    }
    cout << "Primitive roots of " << p << ": ";
    for (int root : primitive_roots) {
        cout << root << " ";
    }
    cout << endl;
    return primitive_roots.empty() ? -1 : primitive_roots[0]; 
}

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        cout << "Modular inverse does not exist!" << endl;
        return -1;
    }
    return (x % m + m) % m;
}


void ElGamal_Key_Generation(int &e1, int &e2, int &p, int &d) {
    cout << "Enter a large prime number P: ";
    cin >> p;
    e1 = findAllPrimitiveRoots(p); 
    if (e1 == -1) {
        cout << "No primitive root found!" << endl;
        exit(0);
    }
    cout << "Using primitive root e1 = " << e1 << endl;
    d = 1 + rand() % (p - 2);  
    e2 = powmod(e1, d, p);  
    cout << "Public Key: (" << e1 << ", " << e2 << ", " << p << ")" << endl;
    cout << "Private Key: " << d << endl;
}


pair<int, int> ElGamal_Encryption(int e1, int e2, int p, char P) {
    int r = 1 + rand() % (p - 2);
    int C1 = powmod(e1, r, p);
    int C2 = (int(P) * powmod(e2, r, p)) % p;
    return {C1, C2};
}


char ElGamal_Decryption(int d, int p, int C1, int C2) {
    int C1_d_inv = modInverse(powmod(C1, d, p), p);
    int P = (C2 * C1_d_inv) % p;
    return (char)P;
}

int main() {
    int e1, e2, p, d;
    ElGamal_Key_Generation(e1, e2, p, d);
    string plaintext;
    cout << "Enter plaintext (alphanumeric): ";
    cin >> plaintext;
    vector<pair<int, int>> ciphertext;
    cout << "Ciphertext: ";
    for (char c : plaintext) {
        auto cipher = ElGamal_Encryption(e1, e2, p, c);
        ciphertext.push_back(cipher);
        cout << "(" << cipher.first << ", " << cipher.second << ") ";
    }
    cout << endl;
    cout << "Decrypted Plaintext: ";
    for (auto cipher : ciphertext) {
        cout << ElGamal_Decryption(d, p, cipher.first, cipher.second);
    }
    cout << endl;
    return 0;
}
