#include <stdio.h>

char firstCapitalLetter(char str[], int index) {
    if (str[index] == '\0') {
        return '\0'; 
    }

    if (str[index] >= 'A' && str[index] <= 'Z') {
        return str[index]; 
    }

    return firstCapitalLetter(str, index + 1); 
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    char result = firstCapitalLetter(inputString, 0);

    if (result != '\0') {
        printf("First capital letter in the string: %c\n", result);
    } else {
        printf("No capital letter found in the string.\n");
    }

    return 0;
}
