#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    int length, i;

    printf("Enter a string: ");
    scanf("%99[^\n]", str); 

    length = strlen(str);

    printf("Individual characters in reverse order: \n");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
