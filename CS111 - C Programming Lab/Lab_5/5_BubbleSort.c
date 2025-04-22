#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void bubbleSort(char str[]) {
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char inputString[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%99s", inputString); 

    bubbleSort(inputString);

    printf("String in ascending order of ASCII values: %s\n", inputString);

    return 0;
}
