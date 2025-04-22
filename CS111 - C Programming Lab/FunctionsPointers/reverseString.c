#include <stdio.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; 
    }

    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    
    reverseString(str, start + 1, end - 1);
}

int main() {
    char inputString[] = "Hello, World!";
    int length = sizeof(inputString) - 1; 

    printf("Original string: %s\n", inputString);

    
    reverseString(inputString, 0, length - 1);

    printf("Reversed string: %s\n", inputString);

    return 0;
}
