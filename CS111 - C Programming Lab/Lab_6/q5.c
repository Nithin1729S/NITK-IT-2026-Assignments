#include <stdio.h>


int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base, exponent;

    printf("Enter value of base: ");
    scanf("%d", &base);

    printf("Enter value of power: ");
    scanf("%d", &exponent);

    int result = power(base, exponent);

    printf("%d to the power of %d is: %d\n", base, exponent, result);

    return 0;
}
