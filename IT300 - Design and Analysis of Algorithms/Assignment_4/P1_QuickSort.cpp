//Randomized Quick Sort function
//Average Time Complexity O(nlogn)
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++) 
	{
		if (arr[j] <= pivot) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_random(vector<int>&arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

void quickSort(vector<int>&arr, int low, int high)
{
	if (low < high) {
		int pi = partition_random(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

bool isSorted(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]) return false;
    }
    return true;
}


int main() {
    cout<<"Make sure to paste your array in in.txt file"<<endl;
    vector<int>arr;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    freopen("in.txt","r",stdin);
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    arr.push_back(INT_MAX);
    quickSort(arr, 0, n);
    cout<<"Sorted Array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    if(isSorted(arr)){
        cout<<"It is sorted"<<endl;
    }else{
        cout<<"It is not sorted"<<endl;
    }
    return 0;
}
