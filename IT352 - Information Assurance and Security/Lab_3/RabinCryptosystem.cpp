#include<bits/stdc++.h>
using namespace std;


bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


long long powerMod(long long a, long long b, long long m) {
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

int modInverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        cout << "Modular inverse does not exist!" << endl;
        return -1;
    }
    return (x % m + m) % m;
}


long long encrypt(long long m, long long n) {
    return powerMod(m, 2, n);
}


vector<long long> decrypt(long long c, long long p, long long q) {
    long long n = p * q;
    
    
    long long mp = powerMod(c, (p + 1) / 4, p);
    long long mq = powerMod(c, (q + 1) / 4, q);
    
    
    long long yp = modInverse(q, p) * q;
    long long yq = modInverse(p, q) * p;
    
    
    long long r1 = (yp * mp + yq * mq) % n;
    long long r2 = (yp * mp - yq * mq) % n;
    long long r3 = (-yp * mp + yq * mq) % n;
    long long r4 = (-yp * mp - yq * mq) % n;
    
    
    if (r1 < 0) r1 += n;
    if (r2 < 0) r2 += n;
    if (r3 < 0) r3 += n;
    if (r4 < 0) r4 += n;
    
    return {r1, r2, r3, r4};
}

int main() {
    
    srand(static_cast<unsigned>(time(0)));

    
    long long p, q;
    cout << "Enter a large prime number P: ";
    cin >> p;
    if (!isPrime(p)) {
        cout << "Error: P is not a prime number!" << endl;
        return 1;
    }
    
    if (p % 4 != 3) {
        cout << "Error: Prime P must be congruent to 3 mod 4 for Rabin cryptosystem." << endl;
        return 1;
    }

    cout << "Enter a large prime number Q: ";
    cin >> q;
    if (!isPrime(q)) {
        cout << "Error: Q is not a prime number!" << endl;
        return 1;
    }
    
    if (q % 4 != 3) {
        cout << "Error: Prime Q must be congruent to 3 mod 4 for Rabin cryptosystem." << endl;
        return 1;
    }

    long long n = p * q;
    cout << "\n--- Key Generation ---" << endl;
    cout << "Public key (n = p * q): " << n << endl;
    cout << "Private key (p, q): (" << p << ", " << q << ")" << endl;

    
    cout << "\nEnter the plaintext (alphanumeric, no spaces): ";
    string plaintext;
    cin >> plaintext;  

    vector<long long> ciphertext;
    cout << "\n--- Encryption ---" << endl;
    cout << "Plaintext characters and their ASCII codes:" << endl;
    for (char ch : plaintext) {
        long long m = static_cast<long long>(ch);
        cout << ch << " -> " << m << endl;
        long long c = encrypt(m, n);
        ciphertext.push_back(c);
    }

    cout << "\nCiphertext values:" << endl;
    for (long long ciph : ciphertext) {
        cout << ciph << " ";
    }
    cout << endl;

    
    cout << "\n--- Decryption ---" << endl;
    string decrypted_text;
    int index = 0;
    for (long long ciph : ciphertext) {
        vector<long long> candidates = decrypt(ciph, p, q);
        cout << "\nFor ciphertext " << ciph << ", possible plaintext (ASCII) values are:" << endl;
        for (long long val : candidates) {
            cout << val << " ";
        }
        cout << endl;

        
        bool found = false;
        for (long long m : candidates) {
            if (m >= 32 && m <= 126) {
                decrypted_text += static_cast<char>(m);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Warning: No valid ASCII candidate found for ciphertext at index " << index << ". ";
            decrypted_text += '?'; 
        }
        index++;
    }

    cout << "\nDecrypted text: " << decrypted_text << endl;

    return 0;
}
