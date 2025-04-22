//Same P1_QuickSort.cpp code is reused here..We use randomized quick sort's partition function to get this done
//We follow an algorithm called Quick Select
//Average Time Complexity O(n) since recursive function wont be called all the time unlike quick sort 
#include<bits/stdc++.h>
using namespace std;

int partition(
    vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int partition_random(vector<int>&arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

int quickSort(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIdx = partition_random(arr, low, high);
        if (pivotIdx == k - 1) {
            return arr[pivotIdx];
        }
        if (pivotIdx > k - 1) {
            return quickSort(arr, low, pivotIdx - 1, k);
        }
        return quickSort(arr, pivotIdx + 1, high, k);
    }
    return -1; 
}

int findKthSmallest(std::vector<int>& arr, int k) {
    return quickSort(arr, 0, arr.size() - 1, k);
}

int main(){
    cout<<"Make sure to paste your array in in.txt file"<<endl;
    vector<int>arr;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int k;
    cout<<"Enter value of k: ";
    cin>>k;
    freopen("in.txt","r",stdin);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<k<<"th smallest element is "<<findKthSmallest(arr,n-k+1);
}