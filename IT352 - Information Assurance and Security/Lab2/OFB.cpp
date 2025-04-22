#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 64;
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
string encrypt(string a, string b) {
    string resultBlock = "";
    for (int i = 0; i < a.length(); i++) {
        resultBlock += (a[i] == b[i] ? '0' : '1');
    }
    return resultBlock;
}
string decrypt(string a, string b) {
    string resultBlock = "";
    for (int i = 0; i < a.length(); i++) {
        resultBlock += (a[i] == b[i] ? '0' : '1');
    }
    return resultBlock;
}

int main() {
    string inputString, keyString;
    cout << "Enter string: ";
    getline(cin, inputString);
    cout << "Enter key: ";
    getline(cin, keyString);
    
    string inputBinaryString = stringToBinary(inputString);
    string keyBinaryString = prepareKey(stringToBinary(keyString));

    string iv = generateIV();
    
    string encryptedString;
    string shiftRegister = iv;

    // Encryption Loop (OFB)
    for (int i = 0; i < inputBinaryString.length(); i += FEEDBACK_SIZE) {
        string afterEncWithKey = encrypt(shiftRegister, keyBinaryString).substr(0, FEEDBACK_SIZE);
        string cipherTextBlock = xor_(afterEncWithKey, inputBinaryString.substr(i, FEEDBACK_SIZE));
        encryptedString += cipherTextBlock;
        shiftRegister = shiftRegister.substr(FEEDBACK_SIZE) + afterEncWithKey;
    }

    cout << "Encrypted binary string: " << encryptedString << endl;

    // Decryption Loop (OFB) - Identical to Encryption
    string decryptedBinaryString;
    shiftRegister = iv;

    for (int i = 0; i < encryptedString.length(); i += FEEDBACK_SIZE) {
        string afterEncWithKey = decrypt(shiftRegister, keyBinaryString).substr(0, FEEDBACK_SIZE);
        string plainTextBlock = xor_(afterEncWithKey, encryptedString.substr(i, FEEDBACK_SIZE));
        decryptedBinaryString += plainTextBlock;
        shiftRegister = shiftRegister.substr(FEEDBACK_SIZE) + afterEncWithKey;
    }

    cout << "Decrypted binary string: " << decryptedBinaryString << endl;

    string decryptedString = binaryToString(decryptedBinaryString);
    cout << "Decrypted string: " << decryptedString << endl;

    return 0;
}
