#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char str[], int length) {
    for (int i = 0; i < length / 2; i++) {
        swap(&str[i], &str[length - i - 1]);
    }
}

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);

    printf("Original string: %s\n", str);

    reverseString(str, length);

    printf("Reversed string: %s\n", str);

    return 0;
}
