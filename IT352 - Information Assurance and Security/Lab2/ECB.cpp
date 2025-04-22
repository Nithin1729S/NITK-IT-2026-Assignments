#include<bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE=64;

string stringToBinary(string str){
    string res;
    for(auto&it:str){
        res+=bitset<8>(it).to_string();
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

string padding(string str){
    if(str.length() % BLOCK_SIZE == 0 ) return str;
    int paddingNeeded= BLOCK_SIZE - (str.length() % BLOCK_SIZE) ;
    str.append(paddingNeeded,'0');
    return str;
}

string prepareKey(string str){
    while(str.length() < BLOCK_SIZE ){
        str+=str;
    }
    return str.substr(0,BLOCK_SIZE);
}


string encrypt(string block, string key) {
    string resultBlock = "";
    for (int i = 0; i < BLOCK_SIZE; i++) {
        resultBlock += (block[i] == key[i] ? '0' : '1');
    }
    return resultBlock;
}

int main(){
    string inputString,keyString;
    cout<<"Enter string: ";
    getline(cin,inputString);
    cout<<"Enter key: ";
    getline(cin,keyString);
    string inputBinaryString=padding(stringToBinary(inputString));
    string keyBinaryString=prepareKey(stringToBinary(keyString));

    string encryptedString;
    for(int i=0;i<inputBinaryString.length();i+=BLOCK_SIZE){
        string block=inputBinaryString.substr(i,BLOCK_SIZE);
        string encryptedBlock=encrypt(block,keyBinaryString);
        encryptedString+=encryptedBlock;
    }
    cout << "Encrypted binary string: " << encryptedString << endl;

    string decryptedBinaryString;
    for(int i=0;i<encryptedString.length();i+=BLOCK_SIZE){
        string block=encryptedString.substr(i,BLOCK_SIZE);
        string decryptedBlock=encrypt(block,keyBinaryString);
        decryptedBinaryString+=decryptedBlock;
    }
    cout << "Decrypted binary string: " << decryptedBinaryString << endl;

    string decryptedString=binaryToString(decryptedBinaryString);
    cout << "Decrypted string: " << decryptedString << endl;
    return 0;
}