#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 64; // Fixed block size

// Convert a string to binary representation
string stringToBinary(string str) {
    string res;
    for (auto &it : str) {
        res += bitset<8>(it).to_string();
    }
    return res;
}

// Convert binary string back to normal string
string binaryToString(string binaryString) {
    string result = "";
    for (int i = 0; i < binaryString.length(); i += 8) {
        string byte = binaryString.substr(i, 8);
        result += char(bitset<8>(byte).to_ulong());
    }
    return result;
}

// Generate a random IV (Initialization Vector)
string generateIV() {
    string iv;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv += (rand() % 2) ? '1' : '0';
    }
    return iv;
}

// Ensure key is at least 64 bits (repeats if too short)
string prepareKey(string str) {
    while (str.length() < BLOCK_SIZE) {
        str += str;
    }
    return str.substr(0, BLOCK_SIZE);
}

// XOR function for binary strings
string xorBinary(string a, string b) {
    string result = "";
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] == b[i] ? '0' : '1');
    }
    return result;
}

// XOR-based encryption function (acts as a simple block cipher)
string xorEncryptDecrypt(string block, string key) {
    return xorBinary(block, key);
}

// CBC Mode Encryption with CTS
string encryptCBC_CTS(string inputBinaryString, string keyBinaryString, string &iv) {
    size_t numFullBlocks = inputBinaryString.length() / BLOCK_SIZE;
    size_t lastBlockSize = inputBinaryString.length() % BLOCK_SIZE;

    vector<string> encryptedBlocks;
    string prevCipherBlock = iv;

    // Encrypt full blocks normally
    for (size_t i = 0; i < numFullBlocks; i++) {
        string block = inputBinaryString.substr(i * BLOCK_SIZE, BLOCK_SIZE);
        string blockXORed = xorBinary(block, prevCipherBlock);
        string encryptedBlock = xorEncryptDecrypt(blockXORed, keyBinaryString);
        encryptedBlocks.push_back(encryptedBlock);
        prevCipherBlock = encryptedBlock;
    }

    // Handle last block with CTS
    if (lastBlockSize > 0) {
        string lastBlock = inputBinaryString.substr(numFullBlocks * BLOCK_SIZE);
        string paddedLastBlock = lastBlock + encryptedBlocks[numFullBlocks - 1].substr(lastBlockSize);
        string encryptedLastFull = xorEncryptDecrypt(xorBinary(paddedLastBlock, prevCipherBlock), keyBinaryString);
        
        // Swap the ciphertext parts
        encryptedBlocks[numFullBlocks] = encryptedLastFull.substr(0, lastBlockSize);
        encryptedBlocks[numFullBlocks - 1] = encryptedLastFull;
    }

    // Combine all ciphertext blocks
    string encryptedString = "";
    for (const string &block : encryptedBlocks) {
        encryptedString += block;
    }

    return encryptedString;
}

// CBC Mode Decryption with CTS
string decryptCBC_CTS(string encryptedBinaryString, string keyBinaryString, string &iv, size_t originalSize) {
    size_t numFullBlocks = originalSize / BLOCK_SIZE;
    size_t lastBlockSize = originalSize % BLOCK_SIZE;

    vector<string> decryptedBlocks;
    string prevCipherBlock = iv;

    // Decrypt full blocks normally
    for (size_t i = 0; i < numFullBlocks; i++) {
        string block = encryptedBinaryString.substr(i * BLOCK_SIZE, BLOCK_SIZE);
        string decryptedBlock = xorEncryptDecrypt(block, keyBinaryString);
        string blockXORed = xorBinary(decryptedBlock, prevCipherBlock);
        decryptedBlocks.push_back(blockXORed);
        prevCipherBlock = block;
    }

    // Handle last block with CTS
    if (lastBlockSize > 0) {
        string encryptedLastFull = decryptedBlocks[numFullBlocks - 1];
        string lastBlock = encryptedBinaryString.substr(numFullBlocks * BLOCK_SIZE, lastBlockSize);
        
        // Swap back the parts
        decryptedBlocks[numFullBlocks - 1] = encryptedLastFull;
        decryptedBlocks.push_back(lastBlock);
    }

    // Combine all plaintext blocks
    string decryptedBinaryString = "";
    for (const string &block : decryptedBlocks) {
        decryptedBinaryString += block;
    }

    // Trim the binary string to the original size
    decryptedBinaryString = decryptedBinaryString.substr(0, originalSize);

    return decryptedBinaryString;
}

int main() {
    string inputString, keyString;
    
    cout << "Enter string: ";
    getline(cin, inputString);
    cout << "Enter key: ";
    getline(cin, keyString);

    // Convert input string to binary and prepare key
    string inputBinaryString = stringToBinary(inputString);
    string keyBinaryString = prepareKey(stringToBinary(keyString));

    // Generate IV
    string iv = generateIV();
    cout << "Generated IV: " << iv << endl;

    // Encrypt
    string encryptedBinaryString = encryptCBC_CTS(inputBinaryString, keyBinaryString, iv);
    cout << "Encrypted binary string: " << encryptedBinaryString << endl;

    // Decrypt
    string decryptedBinaryString = decryptCBC_CTS(encryptedBinaryString, keyBinaryString, iv, inputBinaryString.length());
    cout << "Decrypted binary string: " << decryptedBinaryString << endl;

    // Convert back to text
    string decryptedString = binaryToString(decryptedBinaryString);
    cout << "Decrypted string: " << decryptedString << endl;

    return 0;
}
