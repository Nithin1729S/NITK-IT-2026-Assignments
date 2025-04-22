#include<bits/stdc++.h>
using namespace std;

int bits(int num){
    if(num==0) return 0;
    return 1+bits(num/2);
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"\nNumber of bits : "<<bits(num)<<endl;
    return 0;
}