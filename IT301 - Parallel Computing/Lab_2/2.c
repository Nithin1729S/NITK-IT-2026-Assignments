#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#include <stdlib.h>

void matrix_multiply(double **A, double **B, double **C, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double **allocate_matrix(int size) {
    double **matrix = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }
    return matrix;
}

void free_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    struct timeval TimeValue_Start;
    struct timeval TimeValue_Final;
    long time_start, time_end;
    double sequential_time, parallel_time, speedup, efficiency;

    int sizes[] = {250, 500, 750, 1000, 2000};
    int num_threads_options[] = {1, 2, 4, 8};

    FILE *output_file = fopen("speedup_data.csv", "w");
    fprintf(output_file, "MatrixSize,NumThreads,SequentialTime,ParallelTime,Speedup,Efficiency\n");

    for (int s = 0; s < 5; s++) {
        int size = sizes[s];
        printf("<----------------------------------------------------------------------->\n");
        printf("Matrix Size: %d\n", size);

        double **A = allocate_matrix(size);
        double **B = allocate_matrix(size);
        double **C = allocate_matrix(size);

        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = rand() % 100;
                B[i][j] = rand() % 100;
            }
        }

        for (int t = 0; t < 4; t++) {
            int num_threads = num_threads_options[t];
            omp_set_num_threads(num_threads);

           
            if (num_threads == 1) {
                gettimeofday(&TimeValue_Start, NULL);
                matrix_multiply(A, B, C, size);
                gettimeofday(&TimeValue_Final, NULL);

                time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
                time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
                sequential_time = (time_end - time_start) / 1000000.0;

                printf("Sequential Time in Seconds (T_seq): %lf\n", sequential_time);
            }

            
            gettimeofday(&TimeValue_Start, NULL);
            matrix_multiply(A, B, C, size);
            gettimeofday(&TimeValue_Final, NULL);

            time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
            time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
            parallel_time = (time_end - time_start) / 1000000.0;

            printf("Threads: %d, Parallel Time in Seconds (T_par): %lf\n", num_threads, parallel_time);

            
            speedup = sequential_time / parallel_time;
            efficiency = speedup / num_threads;
            
            
            fprintf(output_file, "%d,%d,%lf,%lf,%lf,%lf\n", size, num_threads, sequential_time, parallel_time, speedup, efficiency);

            printf("Speedup: %lf\n", speedup);
            printf("Efficiency: %lf\n", efficiency);
        }

        free_matrix(A, size);
        free_matrix(B, size);
        free_matrix(C, size);
    }

    fclose(output_file);
    return 0;
}
