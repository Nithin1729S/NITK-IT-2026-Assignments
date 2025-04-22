#include <bits/stdc++.h>
using namespace std;

int main() {
    string plaintext, key, iv;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);
    cout << "Enter IV: ";
    getline(cin, iv);

    if (key.empty() || iv.empty()) {
        cerr << "Error: Key and IV cannot be empty!" << endl;
        return 1;
    }

    char keyChar = key[0];
    char counter = iv[0];

    string encryptedString;
    string filename = "221IT085_IT352P2c.txt";
    ofstream outFile(filename);

    for (size_t i = 0; i < plaintext.size(); i++) {
        int encryptedValue = (counter + keyChar) % 255;
        char ciphertext = plaintext[i] ^ encryptedValue;
        encryptedString += ciphertext;
        counter = (counter + 1) % 255;
    }
    cout << "Encrypted Text: ";
    cout<<encryptedString<<endl;

    string decryptedString;
    counter=iv[0];
    for (size_t i = 0; i < encryptedString.size(); i++) {
        int decryptedValue =(counter + keyChar ) % 255;
        char afterXortext = encryptedString[i] ^ decryptedValue;
        decryptedString += afterXortext;
        counter = (counter + 1) % 255;
    }
    cout << "Decrypted Text: ";
    cout<<decryptedString<<endl;
    return 0;
}

