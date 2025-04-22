#include <stdio.h>
#include <math.h>

int main() {
    int lower = 1, upper = 500;

    printf("Armstrong numbers between %d and %d are:\n", lower, upper);

    for (int num = lower; num <= upper; ++num) {
        int originalNum = num;
        int sum = 0;
        int n = 0;

        while (originalNum != 0) {
            originalNum /= 10;
            ++n;
        }

        originalNum = num;
        while (originalNum != 0) {
            int remainder = originalNum % 10;
            sum += pow(remainder, n);
            originalNum /= 10;
        }

        if (sum == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
