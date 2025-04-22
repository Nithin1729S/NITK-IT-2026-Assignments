#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrixRandom(int **matrix, int rows, int cols, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % (maxValue + 1);
        }
    }
}

void matrixMultiplication(int **A, int **B, int **C, int r1, int c1, int r2, int c2, int i, int j, int k) {
    if (i >= r1 || j >= c2 || k >= c1) {
        return;
    }

    C[i][j] += A[i][k] * B[k][j];

    if (k + 1 < c1) {
        matrixMultiplication(A, B, C, r1, c1, r2, c2, i, j, k + 1);
    } else if (j + 1 < c2) {
        matrixMultiplication(A, B, C, r1, c1, r2, c2, i, j + 1, 0);
    } else if (i + 1 < r1) {
        matrixMultiplication(A, B, C, r1, c1, r2, c2, i + 1, 0, 0);
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the matrices
    printf("Enter dimensions of the first matrix (rows columns): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter dimensions of the second matrix (rows columns): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix dimensions are incompatible for multiplication.\n");
        return 1;
    }

    // Allocate memory for matrices
    int **A = (int **)malloc(r1 * sizeof(int *));
    int **B = (int **)malloc(r2 * sizeof(int *));
    int **C = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; ++i) {
        A[i] = (int *)malloc(c1 * sizeof(int));
        C[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; ++j) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < r2; ++i) {
        B[i] = (int *)malloc(c2 * sizeof(int));
    }

    // Fill matrices with random values
    fillMatrixRandom(A, r1, c1, 100);
    fillMatrixRandom(B, r2, c2, 100);

    // Perform matrix multiplication
    matrixMultiplication(A, B, C, r1, c1, r2, c2, 0, 0, 0);

    // Print matrices and result
    printf("Matrix A:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C (Result of A * B):\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    for (int i = 0; i < r1; ++i) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < r2; ++i) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
