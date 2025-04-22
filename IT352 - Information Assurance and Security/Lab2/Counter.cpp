#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 64; // Full block size for counter

string stringToBinary(string str) {
    string res;
    for (auto &it : str) {
        res += bitset<8>(it).to_string();
    }
    return res;
}

string binaryToString(string binaryString) {
    string result = "";
    for (int i = 0; i < binaryString.length(); i += 8) {
        string byte = binaryString.substr(i, 8);
        result += char(bitset<8>(byte).to_ulong());
    }
    return result;
}

string generateIV() {
    string iv;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv += (rand() % 2) ? '1' : '0';
    }
    return iv;
}

string prepareKey(string str) {
    while (str.length() < BLOCK_SIZE) {
        str += str;
    }
    return str.substr(0, BLOCK_SIZE);
}

string xor_(string a, string b) {
    string resultBlock = "";
    for (int i = 0; i < a.length(); i++) {
        resultBlock += (a[i] == b[i] ? '0' : '1');
    }
    return resultBlock;
}

string encryptCounter(string counter, string key) {
    return xor_(counter, key); // Simple XOR-based encryption (use AES/DES in real cases)
}

int main() {
    srand(time(0)); // Seed randomness

    string inputString, keyString;
    cout << "Enter string: ";
    getline(cin, inputString);
    cout << "Enter key: ";
    getline(cin, keyString);

    string inputBinaryString = stringToBinary(inputString);
    string keyBinaryString = prepareKey(stringToBinary(keyString));
    string iv = generateIV();
    bitset<BLOCK_SIZE> counter(iv);

    string encryptedString;
    for (int i = 0; i < inputBinaryString.length(); i += BLOCK_SIZE) {
        string counterBinary = counter.to_string();
        string encryptedBlock = xor_(encryptCounter(counterBinary, keyBinaryString), inputBinaryString.substr(i, BLOCK_SIZE));
        encryptedString += encryptedBlock;
        counter = bitset<BLOCK_SIZE>(counter.to_ullong() + 1); // Proper counter increment
    }

    cout << "Encrypted binary string: " << encryptedString << endl;

    // Decryption
    counter = bitset<BLOCK_SIZE>(iv);
    string decryptedBinaryString;
    for (int i = 0; i < encryptedString.length(); i += BLOCK_SIZE) {
        string counterBinary = counter.to_string();
        string decryptedBlock = xor_(encryptCounter(counterBinary, keyBinaryString), encryptedString.substr(i, BLOCK_SIZE));
        decryptedBinaryString += decryptedBlock;
        counter = bitset<BLOCK_SIZE>(counter.to_ullong() + 1); // Proper counter increment
    }

    cout << "Decrypted binary string: " << decryptedBinaryString << endl;
    cout << "Decrypted string: " << binaryToString(decryptedBinaryString) << endl;
    return 0;
}
