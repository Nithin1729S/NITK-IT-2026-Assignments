#include <stdio.h>
#include <ctype.h>


void countCharsWords(const char *sentence, int *charCount, int *wordCount) {
    *charCount = 0;
    *wordCount = 0;
    int inWord = 0;

    while (*sentence != '\0') {
        if (!isspace(*sentence)) {
            (*charCount)++;

            if (!inWord) {
                inWord = 1;
                (*wordCount)++;
            }
        } else {
            inWord = 0;
        }

        sentence++;
    }
}

int main() {
    char inputSentence[1000];
    int charCount = 0, wordCount = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", inputSentence);

    
    countCharsWords(inputSentence, &charCount, &wordCount);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);

    return 0;
}
