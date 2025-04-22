#include <iostream>
#include <algorithm>

using namespace std;

int median(int arr[], int size) {
    if (size % 2 == 0)
        return (arr[size / 2] + arr[size / 2 - 1]) / 2;
    else
        return arr[size / 2];
}

int calculateMedian(int arr1[], int arr2[], int size) {
    if (size <= 0)
        return -1;
    if (size == 1)
        return (arr1[0] + arr2[0]) / 2;
    if (size == 2)
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

    int m1 = median(arr1, size);
    int m2 = median(arr2, size);

    if (m1 == m2)
        return m1;

    if (m1 < m2) {
        if (size % 2 == 0)
            return calculateMedian(arr1 + size / 2 - 1, arr2, size - size / 2 + 1);

        return calculateMedian(arr1 + size / 2, arr2, size - size / 2);
    }

    if (size % 2 == 0)
        return calculateMedian(arr2 + size / 2 - 1, arr1, size - size / 2 + 1);

    return calculateMedian(arr2 + size / 2, arr1, size - size / 2);
}

int main() {
    int arr1[] = { 10, 11, 12, 13, 14 };
    int arr2[] = { 21, 22, 23, 24, 25 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (size1 != size2) {
        cout << "Size of both arrays are different" << endl;
        return 0;
    }

    cout << "Median is: " << calculateMedian(arr1, arr2, size1) << endl;

    return 0;
}
