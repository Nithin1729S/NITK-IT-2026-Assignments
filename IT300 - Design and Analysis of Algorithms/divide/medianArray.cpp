#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= high && arr[left] <= pivot)
            left++;
        while (right >= low && arr[right] > pivot)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
}

int findMedianUtil(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return findMedianUtil(arr, low, pivotIndex - 1, k);
        else
            return findMedianUtil(arr, pivotIndex + 1, high, k);
    }
    return -1;
}

int findMedian(int arr[], int size) {
    int medianIndex = size / 2;
    if (size % 2 == 0)
        return (findMedianUtil(arr, 0, size - 1, medianIndex - 1) +
                findMedianUtil(arr, 0, size - 1, medianIndex)) / 2;
    else
        return findMedianUtil(arr, 0, size - 1, medianIndex);
}

int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Median is: " << findMedian(arr, size) << endl;

    return 0;
}
