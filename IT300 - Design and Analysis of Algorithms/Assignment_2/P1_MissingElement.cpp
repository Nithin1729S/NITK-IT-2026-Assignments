//Divide and conquer approach to find missing element in a array consising of elements in range 0 to n, with 1 element missing. n - size of array
//Time Complexity O(n)
//Space Complexity O(n)
#include<bits/stdc++.h>
using namespace std;

void divideConquer(vector<long long>&arr,int low,int high,vector<int>&vis){
    if(low==high){
        vis[arr[low]]++;
    }
    int mid=(low+high)/2;
    if(low<high){
        divideConquer(arr,low,mid,vis);
        divideConquer(arr,mid+1,high,vis);
    }
}
int main()
{
    int n;
    cout<<"Enter no of elements in the array: ";
    cin>>n;
    vector<long long>arr;
    cout<<"Enter array elements: \n";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    // vector<long long>arr{0,1,5,3,4,6};
    // int n=arr.size();
    vector<int>vis(n+1,0);
    divideConquer(arr,0,n-1,vis);
    for(int i=0;i<=n;i++){
        if(vis[i]==0){
            cout<<"Missing Element is "<<i<<endl;
            break;
        }
    }
    return 0;
}