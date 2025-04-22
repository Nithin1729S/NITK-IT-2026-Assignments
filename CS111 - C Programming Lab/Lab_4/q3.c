#include <stdio.h>

int main() {
    char number[50];
    
    printf("Enter any number to print in words: ");
    scanf("%s", number);
    
    printf("In words: ");
    
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            int digit = number[i] - '0';
            switch (digit) {
                case 0:
                    printf("Zero ");
                    break;
                case 1:
                    printf("One ");
                    break;
                case 2:
                    printf("Two ");
                    break;
                case 3:
                    printf("Three ");
                    break;
                case 4:
                    printf("Four ");
                    break;
                case 5:
                    printf("Five ");
                    break;
                case 6:
                    printf("Six ");
                    break;
                case 7:
                    printf("Seven ");
                    break;
                case 8:
                    printf("Eight ");
                    break;
                case 9:
                    printf("Nine ");
                    break;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
