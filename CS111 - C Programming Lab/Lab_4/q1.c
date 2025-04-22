#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateCombinations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            generateCombinations(arr, start + 1, end);
            swap(&arr[start], &arr[i]); 
        }
    }
}

int main() {
    int n = 3; 
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    generateCombinations(arr, 0, n - 1);
    return 0;
}
