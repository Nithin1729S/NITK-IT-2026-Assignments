#include <iostream>
#include <vector>
#include <algorithm>


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}


int quickSelect(std::vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        }

        
        if (pivotIndex > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        }

        
        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1; 
}

int findKthLargest(std::vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k);
}

int main() {
    std::vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << "The " << k << "th largest element is " << findKthLargest(arr, k) << std::endl;
    return 0;
}
