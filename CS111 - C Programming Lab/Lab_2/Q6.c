#include <stdio.h>


int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumOfDigits(num / 10);
}

int main() {
    int number;

 
    printf("Enter an integer: ");
    scanf("%d", &number);

    int sum = sumOfDigits(number);
    printf("Sum of the digits: %d\n", sum);

    return 0;
}
