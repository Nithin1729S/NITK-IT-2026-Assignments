#include <stdio.h>

int RbinarySearch(int arr[], int l, int h, int key) {
    if (l <= h) {
        int mid = l + (h - l) / 2; 
        if (key == arr[mid]) 
            return mid;
        if (key < arr[mid]) 
            return RbinarySearch(arr, l, mid - 1, key); 
        else 
            return RbinarySearch(arr, mid + 1, h, key); 
    return -1;
}}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 7;
    int l = 0;
    int h = n - 1;
    int temp = RbinarySearch(arr, l, h, key); 
    if (temp != -1)
        printf("%d is present in index %d", key, temp);
    else
        printf("Not found.");
    return 0;
}
