#include <stdio.h>

void findLargestSumPair(int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        return;
    }

    int firstMax = arr[0];
    int secondMax = arr[1];

    for (int i = 2; i < size; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] != firstMax) {
            secondMax = arr[i];
        }
    }

    printf("Pair with the largest sum: %d and %d\n", firstMax, secondMax);
    printf("Sum: %d\n", firstMax + secondMax);
}

int main() {
    int arr[] = {4, 2, 7, 10, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    findLargestSumPair(arr, size);

    return 0;
}
