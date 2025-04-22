#include <bits/stdc++.h>
using namespace std;

vector<string> divideIntoBlocks(const string& text, int blockSize) {
    vector<string> blocks;
    for (size_t i = 0; i < text.length(); i += blockSize) {
        blocks.push_back(text.substr(i, blockSize));
    }
    return blocks;
}

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


void padLastBlock(string& block, int blockSize) {
    while (block.length() < blockSize) {
        block += ' '; 
    }
}

string prepareKey(string key,int blockSize){
    while(key.size() < blockSize){
        key+=key;
    }
    return key.substr(0,blockSize);
}


int main() {
    string plaintext, key,iv;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);
    cout << "Enter IV: ";
    getline(cin, iv);
    string filename = "221IT085_IT352P2b.txt";  
    ofstream outFile(filename);

    int blockSize = iv.length();
    if (blockSize == 0) {
        cerr << "Error: Key cannot be empty!" << endl;
        return 0;
    }
    key=prepareKey(key,blockSize);
    vector<string> plaintextBlocks = divideIntoBlocks(plaintext, blockSize);
    
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
    string previousCipherBlock = iv;
    for (const string& block : plaintextBlocks) {
        string blockXORwithPrev = xor_(block, previousCipherBlock); 
        string encryptedBlock = encrypt(blockXORwithPrev, key); 
        ciphertextBlocks.push_back(encryptedBlock); 
        previousCipherBlock = encryptedBlock; 
    }

    cout << "\nEncrypted Blocks:" << endl;
    outFile << "\nEncrypted Blocks:" << endl;
    for (int i = 0; i < ciphertextBlocks.size(); i++) {
        cout << "Block " << i + 1 << ": " << ciphertextBlocks[i] << endl;
        outFile << "Block " << i + 1 << ": " << ciphertextBlocks[i] << endl;
    }

    // Decryption
    vector<string> decryptedBlocks;
    previousCipherBlock = iv;  
    for (const string& block : ciphertextBlocks) {
        string decryptedBlock=decrypt(block,key);
        string blockXORwithPrev = xor_(decryptedBlock, previousCipherBlock);  
        decryptedBlocks.push_back(blockXORwithPrev);  
        previousCipherBlock = block; 
    }

    cout << "\nDecrypted Blocks:" << endl;
    outFile<< "\nDecrypted Blocks:" << endl;
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