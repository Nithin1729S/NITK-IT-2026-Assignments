//Algorithm to find maximum subarray sum of given array.. gives start and end index of the array as well as the subarray
//Bruteforce Time Complexity O(n^2)
//Divide and conquer time complexity O(nlogn)
#include<bits/stdc++.h>
using namespace std;

int Dstart=0;
int Dend=0;
int DmaxSum=-1e9;
int DcurrSum=0;

void divideConquer(vector<int>&arr,int low,int high){
    if(low==high){
        if(DcurrSum==0){
            Dstart=low;
        }
        DcurrSum+=arr[low];
        if(DcurrSum>=DmaxSum){
            DmaxSum=DcurrSum;
            Dend=low;
        }
        if(DcurrSum<0){
            DcurrSum=0;
        }
    }
    int mid=(low+high)/2;
    if(low<high){
        divideConquer(arr,low,mid);
        divideConquer(arr,mid+1,high);
    }
}


long long bruteForce(vector<int>&arr) {
    int n=arr.size();
    int ans = INT_MIN ;
    int start=0;
    int end=0;
    for(int i =0 ; i < n ; i++) {
        int temp(0);
        for(int j=i ; j < n ; j++) {
            temp = temp + arr[j] ; 
            //ans = max(ans, temp) ;
            if(temp>ans){
                ans=temp;
                start=i;
                end=j;
            }
            
        }
    }
    cout<<"\nMax Sum in a subarray :"<<ans<<endl;
    cout<<"\nRequired i = "<<start<<endl;
    cout<<"\nRequired j = "<<end<<endl;
    cout<<"\nThe max sum subarray :";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    return ans ;
}


int main(){
    vector<int>arr;
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Bruteforce algorithm"<<endl;
    bruteForce(arr);

    cout<<"\n-----------------------------";
    cout<<"\nDivide and conquer algorithm"<<endl;
    divideConquer(arr,0,arr.size()-1);
    cout<<"\nMax Sum in a subarray :"<<DmaxSum<<endl;
    cout<<"\nRequired i = "<<Dstart<<endl;
    cout<<"\nRequired j = "<<Dend<<endl;
    cout<<"\nThe max sum subarray :";
    for(int i=Dstart;i<=Dend;i++){
        cout<<arr[i]<<" ";
    }
}
