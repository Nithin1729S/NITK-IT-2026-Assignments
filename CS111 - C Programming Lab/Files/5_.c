#include <stdio.h>

int main() {
    FILE *ptr = fopen("virat.txt", "rb");  // Open the file in binary read mode

    if (ptr == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    fseek(ptr, 0, 2);
    long size = ftell(ptr);

    printf("Size: %ld", size);

    fclose(ptr);

    return 0;
}
