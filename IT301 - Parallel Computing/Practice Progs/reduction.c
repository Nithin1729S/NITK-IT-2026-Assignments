#include <stdio.h>
#include <omp.h>

int main() {
    int i, n = 100;
    int arr[100];
    int sum = 0;

    // Initialize the array with values from 1 to 100
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Parallel region with reduction clause for sum
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += arr[i];  // Each thread works on its own chunk of the array
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
