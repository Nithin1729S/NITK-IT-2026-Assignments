#include <stdio.h>

#define MAX_SIZE 100

void displayAsciiValues(const char arr[], int size) {
    printf("ASCII values of characters in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Character '%c' -> ASCII value: %d\n", arr[i], arr[i]);
    }
}

int main() {
    char characters[MAX_SIZE];
    int size;

    printf("Enter the number of characters in the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid array size.\n");
        return 1; 
    }

    printf("Enter %d characters:\n", size);
    for (int i = 0; i < size; i++) {
        scanf(" %c", &characters[i]);
    }

    displayAsciiValues(characters, size);

    return 0;
}
