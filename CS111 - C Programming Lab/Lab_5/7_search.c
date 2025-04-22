#include <stdio.h>
#include <stdbool.h>

int findCharIndex(const char str[], char letter) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == letter) {
            return i;
        }
        i++;
    }
    return -1; 
}

int main() {
    char inputString[100];
    char searchChar;

    printf("Enter a string: ");
    scanf("%99s", inputString);

    printf("Enter a character to search: ");
    scanf(" %c", &searchChar);

    int index = findCharIndex(inputString, searchChar);

    if (index != -1) {
        printf("'%c' is found at index: %d\n", searchChar, index);
    } else {
        printf("'%c' is not found in the string.\n", searchChar);
    }

    return 0;
}
