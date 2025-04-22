#include <stdio.h>


int stringLength(const char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    
    int len = stringLength(inputString);

    printf("Length of the string: %d\n", len);

    return 0;
}
