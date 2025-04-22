#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    int alphabets = 0, digits = 0, special_chars = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { 
            alphabets++;
        } else if (isdigit(str[i])) { 
            digits++;
        } else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') { 
            special_chars++;
        }
    }

    printf("Total Alphabets: %d\n", alphabets);
    printf("Total Digits: %d\n", digits);
    printf("Total Special Characters: %d\n", special_chars);

    return 0;
}
