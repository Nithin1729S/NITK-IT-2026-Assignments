#include <stdio.h>

int main() {
    FILE *ptr = fopen("integers.txt", "a+");
    for (int i = 1; i <= 100; i++) {
        fprintf(ptr, "%d ", i);
    }

    FILE *ptr1 = fopen("odd.txt", "a");
    FILE *ptr2 = fopen("even.txt", "a");

    fseek(ptr, 0, 0);
    int num;

    while (fscanf(ptr, "%d", &num) != EOF) {
        if (num % 2 != 0) {
            fprintf(ptr1, "%d ", num);
        } else if (num % 2 == 0) {
            fprintf(ptr2, "%d ", num);
        }
    }

    fclose(ptr);
    fclose(ptr1);
    fclose(ptr2);

    return 0;
}
