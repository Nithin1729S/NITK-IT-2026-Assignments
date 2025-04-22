#include <stdio.h>


int findLargestElement(int arr[], int size) {
    
    if (size == 1) {
        return arr[0];
    } else {
        
        int subArrayMax = findLargestElement(arr + 1, size - 1);
        
        
        return (arr[0] > subArrayMax) ? arr[0] : subArrayMax;
    }
}

int main() {
    int arr[] = {10, 4, 8, 15, 7,90};
    int size = sizeof(arr) / sizeof(arr[0]);

    
    int largestElement = findLargestElement(arr, size);

    
    printf("The largest element in the array is: %d\n", largestElement);

    return 0;
}
