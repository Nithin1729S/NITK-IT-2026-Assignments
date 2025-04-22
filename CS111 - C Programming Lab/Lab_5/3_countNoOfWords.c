#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool isSeparator(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int countWords(char str[]) {
    int wordCount = 0;
    int i = 0;

    
    while (isSeparator(str[i])) {
        i++;
    }

    while (str[i] != '\0') {
        if (isSeparator(str[i])) {
            
            wordCount++;

            
            while (isSeparator(str[i])) {
                i++;
            }
        } else {
            i++;
        }
    }

    
    if (!isSeparator(str[i - 1])) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%99[^\n]", str);

    int totalWords = countWords(str);
    printf("Total number of words: %d\n", totalWords);

    return 0;
}
