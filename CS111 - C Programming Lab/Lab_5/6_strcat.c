#include <stdio.h>
#define MAX_LENGTH 100

void concatenateStrings(char result[], const char str1[], const char str2[]) {
    int i = 0, j = 0;

    
    while (str1[i] != '\0') {
        result[j] = str1[i];
        i++;
        j++;
    }

    
    i = 0;
    while (str2[i] != '\0') {
        result[j] = str2[i];
        i++;
        j++;
    }

    
    result[j] = '\0';
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], result[MAX_LENGTH * 2]; 

    printf("Enter the first string: ");
    scanf("%99s", str1); 

    printf("Enter the second string: ");
    scanf("%99s", str2); 

    concatenateStrings(result, str1, str2);

    printf("Concatenated string: %s\n", result);

    return 0;
}
