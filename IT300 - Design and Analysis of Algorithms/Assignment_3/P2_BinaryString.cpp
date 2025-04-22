//Binary Search Solution to find no of zeroes in a given binary string of type {1^m0^n}
//Time Complexity O(logk) where k is length of string
//Space complexity O(k) if given string is considered as extra space too.
#include<bits/stdc++.h>
using namespace std;
// int cnt=0;

// void zeroCount(string s,int low,int high){
//     if(low==high){
//         if(s[low]=='0') cnt++;
//     }
//     if(low<high){
//         int mid=(low+high)/2;
//         zeroCount(s,low,mid);
//         zeroCount(s,mid+1,high);
//     }
// }

int zeroStart(string s){
    int lo=0;
    int hi=s.length()-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(s[lo]=='1'){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    //cout<<lo<<endl;
    return lo;
}
int main(){
    string s;
    cout<<"Enter binary string of form {1^m0^n}: ";
    cin>>s;
    int n=s.size();
    int Zstart=zeroStart(s);
    cout<<"No of Zeroes is "<<n-Zstart<<endl;
    return 0;
    
}