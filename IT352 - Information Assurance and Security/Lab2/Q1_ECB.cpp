#include <bits/stdc++.h>
using namespace std;

vector<string> divideIntoBlocks(const string& text, int blockSize) {
    vector<string> blocks;
    for (size_t i = 0; i < text.length(); i += blockSize) {
        blocks.push_back(text.substr(i, blockSize));
    }
    return blocks;
}

void padLastBlock(string& block, int blockSize) {
    while (block.length() < blockSize) {
        block += ' '; 
    }
}

string encryptBlock(const string& plaintextBlock, const string& key) {
    string ciphertext;
    for (int i = 0; i < plaintextBlock.size(); i++) {
        int plainVal = static_cast<unsigned char>(plaintextBlock[i]);
        int keyVal = static_cast<unsigned char>(key[i]);
        int encryptedValue = (plainVal + keyVal) % 255;
        ciphertext += static_cast<char>(encryptedValue);
    }
    return ciphertext;
}

string decryptBlock(const string& ciphertextBlock, const string& key) {
    string plaintext;
    for (int i = 0; i < ciphertextBlock.size(); i++) {
        int cipherVal = static_cast<unsigned char>(ciphertextBlock[i]);
        int keyVal = static_cast<unsigned char>(key[i]);
        int decryptedValue = ((cipherVal - keyVal) + 255) % 255;
        plaintext += static_cast<char>(decryptedValue);
    }
    return plaintext;
}

int main() {
    string plaintext, key;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);
    string filename = "221IT085_IT352P2a.txt";  
    ofstream outFile(filename);
    int blockSize = key.length();
    if (blockSize == 0) {
        cerr << "Error: Key cannot be empty!" << endl;
        return 0;
    }

    vector<string> plaintextBlocks = divideIntoBlocks(plaintext, blockSize);
    
    // Pad the last block if necessary
    if (!plaintextBlocks.empty()) {
        padLastBlock(plaintextBlocks.back(), blockSize);
    }

    cout << "\nPlaintext Blocks:" << endl;
    outFile<< "\nPlaintext Blocks:" << endl;
    for (int i=0;i<plaintextBlocks.size();i++) {
        cout << "Block" << i+1<<": " << plaintextBlocks[i] << endl;
        outFile << "Block" << i+1<<": " << plaintextBlocks[i] << endl;
    }

    // Encryption
    vector<string> ciphertextBlocks;
    for (const string& block : plaintextBlocks) {
        string encryptedBlock = encryptBlock(block, key);
        ciphertextBlocks.push_back(encryptedBlock);
    }

    cout << "\nEncrypted Blocks:" << endl;
    outFile << "\nEncrypted Blocks:" << endl;
    for (int i=0;i<ciphertextBlocks.size();i++) {
        cout << "Block" << i+1<<": " << ciphertextBlocks[i] << endl;
        outFile << "Block" << i+1<<": " << ciphertextBlocks[i] << endl;
    }

    // Decryption
    vector<string> decryptedBlocks;
    for (const string& block : ciphertextBlocks) {
        string decryptedBlock = decryptBlock(block, key);
        decryptedBlocks.push_back(decryptedBlock);
    }

    cout << "\nDecrypted Blocks:" << endl;
    outFile << "\nDecrypted Blocks:" << endl;
    for (int i=0;i<decryptedBlocks.size();i++) {
        cout << "Block" << i+1<<": " << decryptedBlocks[i] << endl;
        outFile << "Block" << i+1<<": " << decryptedBlocks[i] << endl;
    }

    
    string decryptedString;
    for(auto&it:decryptedBlocks){
        decryptedString+=it;
    }
    
    cout<<"Decrypted String: "<<decryptedString<<endl;
    outFile<<"Decrypted String: "<<decryptedString<<endl;
    return 0;
}