#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 64;

string stringToBinary(string str) {
    string res;
    for (auto &it : str) {
        res += bitset<8>(it).to_string();
    }
    return res;
}

string binaryToString(string binaryString) {
    string result = "";
    for (size_t i = 0; i < binaryString.length(); i += 8) {
        string byte = binaryString.substr(i, 8);
        result += char(bitset<8>(byte).to_ulong());
    }
    return result;
}

string prepareKey(string str) {
    while (str.length() < BLOCK_SIZE) {
        str += str;
    }
    return str.substr(0, BLOCK_SIZE);
}

string xorEncryptDecrypt(string block, string key) {
    string resultBlock = "";
    for (int i = 0; i < block.length(); i++) {
        resultBlock += (block[i] == key[i] ? '0' : '1');
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

    vector<string> blocks;
    size_t numFullBlocks = inputBinaryString.length() / BLOCK_SIZE;
    size_t lastBlockSize = inputBinaryString.length() % BLOCK_SIZE;

    // Divide the input into blocks
    for (size_t i = 0; i < numFullBlocks * BLOCK_SIZE; i += BLOCK_SIZE) {
        blocks.push_back(inputBinaryString.substr(i, BLOCK_SIZE));
    }

    if (lastBlockSize > 0) {
        blocks.push_back(inputBinaryString.substr(numFullBlocks * BLOCK_SIZE, lastBlockSize));
    }

    string encryptedString;
    vector<string> encryptedBlocks;

    // Encrypt all full blocks normally
    for (size_t i = 0; i < numFullBlocks; i++) {
        encryptedBlocks.push_back(xorEncryptDecrypt(blocks[i], keyBinaryString));
    }

    // Handle last block using CTS if it's smaller
    if (lastBlockSize > 0) {
        string paddedLastBlock = blocks[numFullBlocks]; // Smaller block
        string encryptedLastFull = xorEncryptDecrypt(paddedLastBlock, keyBinaryString); // Encrypt as full block

        // Swap last two encrypted blocks
        encryptedBlocks.push_back(encryptedLastFull.substr(0, lastBlockSize));
        encryptedBlocks[numFullBlocks - 1] = encryptedLastFull;
    }

    for (const string &block : encryptedBlocks) {
        encryptedString += block;
    }

    cout << "Encrypted binary string: " << encryptedString << endl;

    // Decryption process
    string decryptedBinaryString;
    vector<string> decryptedBlocks(numFullBlocks + (lastBlockSize > 0 ? 1 : 0));

    // Decrypt all full blocks
    for (size_t i = 0; i < numFullBlocks; i++) {
        decryptedBlocks[i] = xorEncryptDecrypt(encryptedBlocks[i], keyBinaryString);
    }

    // Handle last block during decryption
    if (lastBlockSize > 0) {
        string lastCipherText = encryptedBlocks[numFullBlocks]; // Partial last block
        string fullDecryptedBlock = xorEncryptDecrypt(encryptedBlocks[numFullBlocks - 1], keyBinaryString);

        decryptedBlocks[numFullBlocks - 1] = fullDecryptedBlock;
        decryptedBlocks[numFullBlocks] = lastCipherText;
    }

    for (const string &block : decryptedBlocks) {
        decryptedBinaryString += block;
    }

    cout << "Decrypted binary string: " << decryptedBinaryString << endl;
    cout << "Decrypted string: " << binaryToString(decryptedBinaryString) << endl;

    return 0;
}
