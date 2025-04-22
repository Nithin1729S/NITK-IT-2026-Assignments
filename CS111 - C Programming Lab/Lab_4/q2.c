#include <stdio.h>

int main() {
    int number, firstDigit, lastDigit;

    
    printf("Enter a number: ");
    scanf("%d", &number);

   
    lastDigit = number % 10;

    
    while (number >= 10) {
        number /= 10;
    }
    firstDigit = number;

 
    int sum = firstDigit + lastDigit;
    printf("Sum of the first and last digits: %d\n", sum);

    return 0;
}
