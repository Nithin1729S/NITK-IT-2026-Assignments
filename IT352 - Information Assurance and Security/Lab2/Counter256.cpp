#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 256; // 256-bit counter
const int FEEDBACK_SIZE = 8;

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
    return xor_(counter, key); // Simple XOR-based encryption (can be replaced by a proper block cipher)
}

void incrementCounter(string &counter) {
    for (int i = counter.length() - 1; i >= 0; i--) {
        if (counter[i] == '0') {
            counter[i] = '1';
            break;
        } else {
            counter[i] = '0';
        }
    }
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
    string counter = generateIV();
    
    string encryptedString;
    for (int i = 0; i < inputBinaryString.length(); i += FEEDBACK_SIZE) {
        string encryptedBlock = xor_(encryptCounter(counter, keyBinaryString).substr(0, FEEDBACK_SIZE), inputBinaryString.substr(i, FEEDBACK_SIZE));
        encryptedString += encryptedBlock;
        incrementCounter(counter);
    }
    
    cout << "Encrypted binary string: " << encryptedString << endl;
    
    // Decryption
    counter = generateIV();
    string decryptedBinaryString;
    for (int i = 0; i < encryptedString.length(); i += FEEDBACK_SIZE) {
        string decryptedBlock = xor_(encryptCounter(counter, keyBinaryString).substr(0, FEEDBACK_SIZE), encryptedString.substr(i, FEEDBACK_SIZE));
        decryptedBinaryString += decryptedBlock;
        incrementCounter(counter);
    }
    
    cout << "Decrypted binary string: " << decryptedBinaryString << endl;
    cout << "Decrypted string: " << binaryToString(decryptedBinaryString) << endl;
    return 0;
}
