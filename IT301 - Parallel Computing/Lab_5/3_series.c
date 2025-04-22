#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sizes[]={5000,10000,50000,1000000};
    FILE *fp = fopen("execution_times.csv", "a"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "ArraySize,ExecutionTime\n");
    for(int i=0;i<4;i++){
        int n = sizes[i];  
        int *A = (int*)malloc(n * sizeof(int));
        int *B = (int*)malloc(n * sizeof(int));
        int *C = (int*)malloc(n * sizeof(int));
        srand(time(0));
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 100;
            B[i] = rand() % 100;
        }
        clock_t start = clock();
        for (int i = 0; i < n; i++) {
            C[i] = A[i] + B[i];
        }
        clock_t end = clock();
        double total_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sequential execution time of array of size %d : %f seconds\n", n,total_time);
        fprintf(fp, "%d, %f\n", n, total_time);  
        free(A);
        free(B);
        free(C);
    }
    fclose(fp);
    return 0;
}
