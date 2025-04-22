#include <stdio.h>


void stringConcat(char *dest, const char *src) {
    
    while (*dest != '\0') {
        dest++;
    }

    
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    
    *dest = '\0';
}

int main() {
    char firstString[100], secondString[100];

    printf("Enter the first string: ");
    scanf("%s", firstString);

    printf("Enter the second string: ");
    scanf("%s", secondString);

    
    stringConcat(firstString, secondString);

    printf("Concatenated string: %s\n", firstString);

    return 0;
}
