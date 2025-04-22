#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int main() {
    int sizes[] = {5000, 10000, 50000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int thread_counts[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int num_thread_counts = sizeof(thread_counts) / sizeof(thread_counts[0]);
    FILE *fp = fopen("execution_times.csv", "w"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "ArraySize,ThreadCount,Schedule,ExecutionTime\n");
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];  
        int *A = (int*)malloc(n * sizeof(int));
        int *B = (int*)malloc(n * sizeof(int));
        int *C = (int*)malloc(n * sizeof(int));
        if (A == NULL || B == NULL || C == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            free(A);
            free(B);
            free(C);
            continue;
        }
        srand(time(0));
        for (int j = 0; j < n; j++) {
            A[j] = rand() % 100;
            B[j] = rand() % 100;
        }
        double start_time = omp_get_wtime();
        for (int j = 0; j < n; j++) {
            C[j] = A[j] + B[j];
        }
        double end_time = omp_get_wtime();
        double serial_time = end_time - start_time;
        fprintf(fp, "%d,1,serial,%.6f\n", n, serial_time);
        printf("Serial execution time for array size %d: %f seconds\n", n, serial_time);
        for (int t = 0; t < num_thread_counts; t++) {
            int num_threads = thread_counts[t];
            if (num_threads == 1) {
                continue;
            }
            omp_set_num_threads(num_threads); 
            start_time = omp_get_wtime();
            #pragma omp parallel for schedule(runtime)
            for (int j = 0; j < n; j++) {
                C[j] = A[j] + B[j];
            }
            end_time = omp_get_wtime();
            double parallel_time = end_time - start_time;
            fprintf(fp, "%d,%d,runtime,%.6f\n", n, num_threads, parallel_time);
            printf("Parallel execution time for array size %d with %d threads (runtime schedule): %f seconds\n", n, num_threads, parallel_time);
        }
        free(A);
        free(B);
        free(C);
    }
    fclose(fp);
    printf("Execution times have been recorded in 'execution_times.csv'.\n");
    return 0;
}
