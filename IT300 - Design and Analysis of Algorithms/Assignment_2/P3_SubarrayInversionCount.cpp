//Find the sum of the total number of inversions in all sub-arrays of X of length l.
//Time Complexity O(n^2 logn)
//Space Complexity O(n^2)
#include<bits/stdc++.h>
using namespace std;
long long countInv=0;

void merge(vector<long long>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
            countInv+=(mid-left+1);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
        
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<long long>&arr,int low,int high){
    int mid=(low+high)/2;
    if(low<high){
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


void generateSubarrays(vector<long long>&arr,int l){
    vector<vector<long long>>subarrays;
    for(int i=0;i<=arr.size()-l;i++){
        vector<long long>temp{arr.begin()+i,arr.begin()+i+l};
        subarrays.push_back(temp);
    }
    for(auto &it:subarrays){
        mergeSort(it,0,it.size()-1);
    }
    // for(auto it:subarrays){
    //     for(auto&ele:it){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main()
{
    //freopen('r',"Counting Inversions-Test-Case-I.txt")
    int n,l;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter the subarray size: ";
    cin>>l;
    vector<long long>arr;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    // vector<long long>arr{54044,14108,79294,29649,25260,60660,2995,53777,49689,9083};
    // int n=arr.size();
    generateSubarrays(arr,l);
    cout<<"\nNo of Inversions: "<<countInv<<endl;
    return 0;
}