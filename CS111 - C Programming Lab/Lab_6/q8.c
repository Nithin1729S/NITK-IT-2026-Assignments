#include <stdio.h>
#include <ctype.h>


void countVowelsConsonants(const char *str, int *vowelCount, int *consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;

    while (*str != '\0') {
        char ch = toupper(*str);

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            (*vowelCount)++;
        } else if (ch >= 'A' && ch <= 'Z') {
            (*consonantCount)++;
        }

        str++;
    }
}

int main() {
    char inputString[100];
    int vowelCount = 0, consonantCount = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", inputString);

    
    countVowelsConsonants(inputString, &vowelCount, &consonantCount);

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
