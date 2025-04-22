#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define ASCII_SIZE 256

char findMaxOccurringChar(char str[]) {
    int charCount[ASCII_SIZE] = {0};
    int maxCount = 0;
    char maxChar;
    int length = strlen(str);
    int i;

    
    for (i = 0; i < length; i++) {
        charCount[str[i]]++;
        if (charCount[str[i]] > maxCount) {
            maxCount = charCount[str[i]];
            maxChar = str[i];
        }
    }

    return maxChar;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string without spaces: ");
    scanf("%99s", str); 

    char maxChar = findMaxOccurringChar(str);

    printf("Maximum occurring character: %c\n", maxChar);

    return 0;
}
