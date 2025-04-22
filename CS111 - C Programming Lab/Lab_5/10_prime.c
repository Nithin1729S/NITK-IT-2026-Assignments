#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void displayPrimeNumbers(int start, int end) {
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int start, end;

    printf("Enter the starting number of the interval: ");
    scanf("%d", &start);

    printf("Enter the ending number of the interval: ");
    scanf("%d", &end);

    printf("\n");

    if (start >= end || start < 0 || end < 0) {
        printf("Invalid input for interval.\n");
        return 1; 
    }

    displayPrimeNumbers(start, end);

    return 0;
}
