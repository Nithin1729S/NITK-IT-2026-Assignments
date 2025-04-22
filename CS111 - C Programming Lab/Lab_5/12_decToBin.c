#include <stdio.h>


void decimalToBinary(int num) {
    int binary[32]; 
    int index = 0;

    
    if (num == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    printf("Binary equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToBinary(decimalNumber);

    return 0;
}
