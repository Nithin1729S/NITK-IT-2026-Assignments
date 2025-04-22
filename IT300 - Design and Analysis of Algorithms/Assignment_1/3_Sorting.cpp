#include<bits/stdc++.h>
using namespace std;

void sortBruteRecursive(vector<int>&nums,int n){
    if(n==1){
        return;
    }
    int count=0;
    for (int i=0; i<n-1; i++) 
        if (nums[i] > nums[i+1]){ 
            swap(nums[i],nums[i+1]); 
            count++; 
        } 
      if (count==0) 
           return; 
    sortBruteRecursive(nums, n-1); 

}
int main(){
    vector<int>nums;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements of the array: ";
    for(int i=0;i<n;i++) {
        int n;
        cin>>n;
        nums.push_back(n);
    }
    sortBruteRecursive(nums,nums.size());
    for(auto&it:nums) cout<<it<<" ";
    cout<<endl;
}