#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *file;

    
    file = fopen("output.txt", "w");

    
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    
    printf("Enter text to write to the file:\n");
    char input[100];
    fgets(input, sizeof(input), stdin);

    
    fprintf(file, "%s", input);

    
    fclose(file);

    
    file = fopen("output.txt", "r");

    
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    
    printf("\nContent read from the file:\n");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    
    fclose(file);

    return 0;
}

