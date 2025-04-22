#include<bits/stdc++.h>
using namespace std;

const vector<int>PC1{
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
};

const vector<int>PC2{
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};


string convertToBin(string str){
    string res="";
    for(auto it:str){
        res+=bitset<8>(it).to_string();
    }
    cout<<"Binary String: "<<res<<endl;
    
    if (res.size() > 64) {
        return res.substr(0, 64);
    } else if (res.size() < 64) {
        return res + string(64 - res.size(), '0');
    }
    return res;
}


string leftShift(const string &key, int shifts) {
    return key.substr(shifts) + key.substr(0, shifts);
}


vector<string> generateRoundKeys(const string &binaryKey) {

    string permutedKey="";
    for(auto i:PC1){
        permutedKey+=binaryKey[i-1];
    }

    string left = permutedKey.substr(0, 28);
    string right = permutedKey.substr(28, 28);

    vector<string> roundKeys; 

    for (int i = 0; i < 16; i++) {

        int shifts = (i == (1-1) || i == (2-1) || i == (9-1) || i == (16-1)) ? 1 : 2;

        left = leftShift(left, shifts);
        right = leftShift(right, shifts);

        string combined = left + right;
        string roundKey="";
        for(auto i:PC2){
            roundKey+=combined[i-1];
        }

        roundKeys.push_back(roundKey); 
    }

    return roundKeys;
}


int main(){
    string inputKey;
    cout << "Enter an alphanumeric string (max 8 characters): ";
    cin >> inputKey;

    string binaryKey = convertToBin(inputKey);
    cout << "Binary Key: " << binaryKey << endl;

    vector<string> roundKeys = generateRoundKeys(binaryKey);

    ofstream outFile("round_keys.txt");
    for (int i = 0; i < roundKeys.size(); i++) {
        cout << "Round " << i + 1 << " Key: " << roundKeys[i] << endl;
        outFile << "Round " << i + 1 << " Key: " << roundKeys[i] << endl;
    }
    outFile.close();
    return 0;
}