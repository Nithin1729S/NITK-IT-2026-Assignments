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

int modInverse(int e, int phi) {
    int x, y;
    int g = extended_gcd(e, phi, x, y);
    if (g != 1) {
        cout << "Modular inverse does not exist!" << endl;
        return -1;
    }
    return (x % phi + phi) % phi;
}

int main() {
    int p, q;
    cout << "Enter two prime numbers (p and q, larger than 50 recommended): ";
    cin >> p >> q;
    
    int N = p * q;
    int phi = (p - 1) * (q - 1);
    
    int e;
    for (int i = 2; i < phi; i++) {
        if (__gcd(i, phi) == 1) { 
            e = i;
            break;
        }
    }

    int d = modInverse(e, phi);
    if (d == -1) return 0;
    
    cout << "Public Key: (" << e << ", " << N << ")" << endl;
    cout << "Private Key: " << d << endl;

    string plaintext;
    cout << "Enter message to encrypt (alphanumeric only): ";
    cin >> plaintext;
    
    vector<long long> encrypted_text;
    cout << "Encrypted message: ";
    for (char ch : plaintext) {
        long long cipher = binpow((long long)ch, e, N);
        encrypted_text.push_back(cipher);
        cout << cipher << " ";
    }
    cout << endl;
    
    cout << "Decrypted message: ";
    for (long long cipher : encrypted_text) {
        char decrypted_char = (char)binpow(cipher, d, N);
        cout << decrypted_char;
    }
    cout << endl;
    
    return 0;
}