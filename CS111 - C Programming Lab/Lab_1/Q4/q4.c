#include <stdio.h>

int main() {
    double number, result;
    double guess, epsilon = 0.00001;

    printf("Enter a number: ");
    scanf("%lf", &number);

    if (number >= 0) {
        guess = number / 2.0;

        while ((guess * guess - number) >= epsilon) {
            guess = 0.5 * (guess + number / guess);
        }

        printf("Square root of %.2lf is approximately %.5lf\n", number, guess);
    } else {
        printf("Invalid input. The number must be non-negative.\n");
    }

    return 0;
}

