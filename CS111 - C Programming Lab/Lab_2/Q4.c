#include <stdio.h>

int main() {
    char romanNumeral;
    int decimalNumber = 0;


    while (1) {
        printf("Enter a Roman numeral (I, V, X, L, C, D, M) or 'Q' to quit: ");
        scanf(" %c", &romanNumeral);

        
        switch (romanNumeral) {
            case 'I':
                decimalNumber += 1;
                break;
            case 'V':
                decimalNumber += 5;
                break;
            case 'X':
                decimalNumber += 10;
                break;
            case 'L':
                decimalNumber += 50;
                break;
            case 'C':
                decimalNumber += 100;
                break;
            case 'D':
                decimalNumber += 500;
                break;
            case 'M':
                decimalNumber += 1000;
                break;
            case 'Q':
              
                goto end;
            default:
                printf("Invalid input. Please enter a valid Roman numeral.\n");
        }
    }

    end:
    
    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}
