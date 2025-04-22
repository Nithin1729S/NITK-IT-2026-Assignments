#include<stdio.h>

void insert(int arr[], int *n, int key, int idx) {
    for (int i = *n; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
    arr[idx] = key;
    (*n)++;
}

int main() {
    int n = 5;
    int arr[100] = {1, 2, 3, 4, 5};
    insert(arr, &n, 100, 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
