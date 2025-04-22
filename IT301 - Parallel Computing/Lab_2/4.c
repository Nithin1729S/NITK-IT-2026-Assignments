#include <stdio.h>
#include <omp.h>

#define SIZE 5

int main() {
    int i;
    int a[SIZE]; 
    int b[SIZE]; 
    int c[SIZE]; 

    
    printf("Enter %d elements for vector a: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }

    
    printf("Enter %d elements for vector b: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &b[i]);
    }

    omp_set_num_threads(SIZE);

    
    #pragma omp parallel for
    for (i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    
    printf("Result vector: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
