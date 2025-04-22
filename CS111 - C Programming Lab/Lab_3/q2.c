#include <stdio.h>

int main() {
    int decimalNum;
    
    
    printf("Enter a positive integer: ");
    scanf("%d", &decimalNum);

    if (decimalNum < 0) {
        printf("Please enter a positive integer.\n");
        return 1; 
    }

    printf("Binary equivalent: ");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        int bit = (decimalNum >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    return 0;
}
