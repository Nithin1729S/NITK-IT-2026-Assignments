#include <stdio.h>


void hailstoneSequence(int n) {
    printf("%d ", n);

    if (n == 1) {
        return;
    } else if (n % 2 == 0) {
        hailstoneSequence(n / 2);
    } else {
        hailstoneSequence((n * 3) + 1);
    }
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Hailstone Sequence for %d: ", number);
        hailstoneSequence(number);
        printf("\n");
    }

    return 0;
}
