#include<bits/stdc++.h>
using namespace std;

const vector<int>E_BOX{
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1
};
ofstream my_file("out.txt");

string convertToBin(string str){
    string res="";
    for(auto it:str){
        res+=bitset<8>(it).to_string();
    }
    my_file<<"Binary String: "<<res<<endl;
    cout<<"Binary String: "<<res<<endl;
    
    if (res.size() > 64) {
        return res.substr(0, 64);
    } else if (res.size() < 64) {
        return res + string(64 - res.size(), '0');
    }
    return res;
}

string expansion(string str){
    string left=str.substr(0,32);
    string right=str.substr(32,32);
    cout<<"Left Part: "<<left<<endl;
    my_file<<"Left Part: "<<left<<endl;
    cout<<"Right Part: "<<right<<endl;
    my_file<<"Right Part: "<<right<<endl;
    string expandedRight="";
    for(int i:E_BOX){
        expandedRight+=right[i-1];
    }
    return expandedRight;
}

int main(){
    string str;
    cout<<"Enter a string of 8 characters: "<<endl;
    cin>>str;
    string bstr=convertToBin(str);
    string expandedRight=expansion(bstr);
    cout<<"Expanded Right:"<<expandedRight<<endl;
    my_file<<"Expanded Right:"<<expandedRight<<endl;
    return 0;
}