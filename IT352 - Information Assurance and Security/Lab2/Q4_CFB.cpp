#include <bits/stdc++.h>
using namespace std;

string xor_(const string& a, const string& b) {
    string result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] ^ b[i]);
    }
    return result;
}

string encrypt(const string& block, const string& key) {
    string encryptedBlock;
    for (int i = 0; i < block.size(); ++i) {
        encryptedBlock.push_back((block[i] + key[i]) % 255);
    }
    return encryptedBlock;
}

string decrypt(const string& block, const string& key) {
    string decryptedBlock;
    for (int i = 0; i < block.size(); ++i) {
        decryptedBlock.push_back((block[i] - key[i]) % 255);
    }
    return decryptedBlock;
}

string prepareKey(string key, int blockSize) {
    while (key.size() < blockSize) {
        key += key;
    }
    return key.substr(0, blockSize);
}

string cfbEncrypt(const string& plaintext, const string& key, const string& iv, int blockSize) {
    string encryptedString;
    string shiftRegister = iv;

    for (int i = 0; i < plaintext.length(); i += blockSize) {
        string block = plaintext.substr(i, blockSize);
        string encryptedShiftReg = encrypt(shiftRegister, key).substr(0, blockSize);
        string ciphertextBlock = xor_(block, encryptedShiftReg);
        encryptedString += ciphertextBlock;
        shiftRegister = shiftRegister.substr(blockSize) + ciphertextBlock;
    }
    return encryptedString;
}

string cfbDecrypt(const string& ciphertext, const string& key, const string& iv, int blockSize) {
    string decryptedString;
    string shiftRegister = iv;

    for (int i = 0; i < ciphertext.length(); i += blockSize) {
        string block = ciphertext.substr(i, blockSize);
        string encryptedShiftReg = encrypt(shiftRegister, key).substr(0, blockSize);
        string plaintextBlock = xor_(block, encryptedShiftReg);
        decryptedString += plaintextBlock;
        shiftRegister = shiftRegister.substr(blockSize) + block;
    }
    return decryptedString;
}

int main() {
    string plaintext, key, iv;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);
    cout << "Enter IV: ";
    getline(cin, iv);

    string filename = "221IT085_IT352P2d.txt";  
    ofstream outFile(filename);

    int blockSize = 2;  
    if (iv.empty()) {
        cerr << "Error: IV cannot be empty!" << endl;
        return 0;
    }

    key = prepareKey(key, blockSize);  

    string encryptedText = cfbEncrypt(plaintext, key, iv, blockSize);
    cout << "\nEncrypted Text: " << encryptedText << endl;
    outFile << "\nEncrypted Text: " << encryptedText << endl;

    string decryptedText = cfbDecrypt(encryptedText, key, iv, blockSize);
    cout << "\nDecrypted Text: " << decryptedText << endl;
    outFile << "\nDecrypted Text: " << decryptedText << endl;

    outFile.close();
    return 0;
}
