//Count inversion in a given array
//Time Complexity O(nlogn)
//Space Complexity O(n)
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
int main()
{
    //freopen('r',"Counting Inversions-Test-Case-I.txt")
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<long long>arr;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    // vector<long long>arr{6,5,4,3,2,1};
    // int n=arr.size();
    mergeSort(arr,0,n-1);
    cout<<"\nNo of Inversions: "<<countInv<<endl;
    return 0;
}