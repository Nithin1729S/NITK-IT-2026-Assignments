#include <stdio.h>

int main() {
    
    FILE *file;

    
    file = fopen("new.txt", "w");

    
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    
    int value1, value2;
    printf("Enter the first number: ");
    scanf("%d", &value1);
    printf("Enter the second number: ");
    scanf("%d", &value2);

    
    fprintf(file, "%d %d", value1, value2);

    
    fclose(file);

    
    file = fopen("new.txt", "r");

    
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    
    fseek(file, 0, SEEK_SET);  
    int readValue1, readValue2;
    fscanf(file, "%d %d", &readValue1, &readValue2);

    
    fclose(file);

    
    int result = readValue1 + readValue2;

    
    file = fopen("new.txt", "a");

    
    if (file == NULL) {
        perror("Error opening file for appending");
        return 1;
    }

    
    fprintf(file, "\nResult: %d", result);

    
    fclose(file);

    
    printf("Result: %d\n", result);

    return 0;
}
