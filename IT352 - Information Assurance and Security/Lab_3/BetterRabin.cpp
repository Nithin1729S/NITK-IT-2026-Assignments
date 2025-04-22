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
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}


long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) {
        cerr << "Modular inverse does not exist for a = " << a << " and m = " << m << endl;
        exit(1);
    }
    return (x % m + m) % m;
}





long long Chinese_Remainder(long long r1, long long r2, long long p, long long q) {
    long long n = p * q;
    
    long long inv_q_mod_p = modInverse(q, p);
    long long inv_p_mod_q = modInverse(p, q);
    
    long long x = (r1 * q % n * inv_q_mod_p + r2 * p % n * inv_p_mod_q) % n;
    return (x + n) % n;
}




vector<long long> Rabin_Decryption(long long p, long long q, long long C) {
    
    long long exp_p = (p + 1) / 4;
    long long exp_q = (q + 1) / 4;
    
    
    long long a1 = powerMod(C, exp_p, p);
    long long a2 = (p - a1) % p;  
    
    
    long long b1 = powerMod(C, exp_q, q);
    long long b2 = (q - b1) % q;  
    
    
    vector<long long> plaintexts;
    plaintexts.push_back( Chinese_Remainder(a1, b1, p, q) );
    plaintexts.push_back( Chinese_Remainder(a1, b2, p, q) );
    plaintexts.push_back( Chinese_Remainder(a2, b1, p, q) );
    plaintexts.push_back( Chinese_Remainder(a2, b2, p, q) );
    
    return plaintexts;
}


long long encrypt(long long m, long long n) {
    return powerMod(m, 2, n);
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    
    long long p, q;
    cout << "Enter a large prime number P (congruent to 3 mod 4): ";
    cin >> p;
    if (!isPrime(p)) {
        cout << "Error: P is not a prime number!" << endl;
        return 1;
    }
    if (p % 4 != 3) {
        cout << "Error: Prime P must be congruent to 3 mod 4 for the Rabin cryptosystem." << endl;
        return 1;
    }
    
    cout << "Enter a large prime number Q (congruent to 3 mod 4): ";
    cin >> q;
    if (!isPrime(q)) {
        cout << "Error: Q is not a prime number!" << endl;
        return 1;
    }
    if (q % 4 != 3) {
        cout << "Error: Prime Q must be congruent to 3 mod 4 for the Rabin cryptosystem." << endl;
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
    for (char ch : plaintext) {
        long long m = static_cast<long long>(ch);
        long long c = encrypt(m, n);
        ciphertext.push_back(c);
        cout << ch << " -> ASCII: " << m << " -> Ciphertext: " << c << endl;
    }
    
    cout << "\n--- Decryption ---" << endl;
    string decrypted_text;
    int index = 0;
    for (long long C : ciphertext) {
        cout << "\nDecrypting ciphertext: " << C << endl;
        
        vector<long long> candidates = Rabin_Decryption(p, q, C);
        cout << "Candidate plaintext (ASCII) values:" << endl;
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
