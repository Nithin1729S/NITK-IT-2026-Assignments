#include <stdio.h>

void copyString(char *destination, const char *source) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; 
}

int main() {
    char sourceString[100];
    char destinationString[100];

    printf("Enter a string: ");
    scanf("%99s", sourceString); 

    copyString(destinationString, sourceString);

    printf("Copied string: %s\n", destinationString);

    return 0;
}
