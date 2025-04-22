/*Write a RECURSIVE program using C/C++ to implement a matrix multiplication method of
two integer matrices, with minimum row and column dimensions of ten.
This matrix must be generated with a random function generator and the range of element
must be between 1 and 100.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For seeding the random number generator
#define ub 100
#define lb 1

int **allocateMatrix(int rows, int cols)
{
    // Function to dynamically allocate 2D matrix
    int **matrix;
    matrix = (int **)calloc(rows, sizeof(int *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        if (!matrix[i])
            return NULL;
    }
    return matrix;
}

int **multiplyMatrices(int **A, int **B, int **R, int rA, int cA, int rB, int cB)
{

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            R[i][j] = 0;
            for (int k = 0; k < cA; k++)
            {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return R;
}

int **RmultiplyMatrices(int **A, int **B, int **R, int rA, int cA, int rB, int cB)
{
    // Function to recursively multiply two matrices.
    static int i = 0, j = 0, k = 0;

    if (i >= rA)
    {
        return NULL;
    }
    else if (i < rA)
    {
        if (j < cB)
        {
            if (k < cA)
            {
                R[i][j] += A[i][k] * B[k][j];
                k++;
                RmultiplyMatrices(A, B, R, rA, cA, rB, cB);
            }
            k = 0;
            j++;
            RmultiplyMatrices(A, B, R, rA, cA, rB, cB);
        }
        j = 0;
        i++;
        RmultiplyMatrices(A, B, R, rA, cA, rB, cB);
    }
    return R;
}

void fillRandomValues(int **matrix, int rows, int cols)
{
    // Function to fill the 2D dynamic matrix with random values.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (rand() % (ub - lb + 1)) + lb; // Generate random values between 1 and 100 including 1 and 100...
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    // Function to print the 2D Dynamic Matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows)
{
    // Function to free the dynamically allocated memory in heap.
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    matrix = NULL;
}

int main()
{

    int **A, **B, **R1, **R2, rA, cA, rB, cB;
    do
    {
        printf("Enter the dimensions (rows columns) of the first matrix separated by spaces(minimum 10): ");
        scanf("%d %d", &rA, &cA);
        printf("Enter the dimensions (rows columns) of the second matrix separated by spaces(minimum 10): ");
        scanf("%d %d", &rB, &cB);
        if (rA == 0 || rB == 0 || cA == 0 || cB == 0)
        {
            printf("Invalid Dimensions!Please enter a valid number.\n");
        }
        else if (rA < 10 || rB < 10 || cA < 10 || cB < 10)
            printf("Minimum row and column dimension is 10. Please enter a valid number.\n");
    } while (rA < 10 || rB < 10 || cA < 10 || cB < 10);

    if (rA == 0 || rB == 0 || cA == 0 || cB == 0)
    {
        printf("Invalid Dimensions!");
        return 0;
    }

    if (cA != rB)
    {
        printf("Matrix Multiplication is not possible!");
        return 0;
    }

    srand(time(0));
    A = allocateMatrix(rA, cA);
    srand(rand());
    B = allocateMatrix(rB, cB);
    R1 = allocateMatrix(rA, cB);
    R2 = allocateMatrix(rA, cB);

    fillRandomValues(A, rA, cA);
    fillRandomValues(B, rB, cB);

    printf("Matrix 1:\n");
    printMatrix(A, rA, cA);
    printf("Matrix 2:\n");
    printMatrix(B, rB, cB);

    R1 = multiplyMatrices(A, B, R1, rA, cA, rB, cB);
    printf("The Result of multiplication:\n");
    printMatrix(R1, rA, cB);

    R2 = RmultiplyMatrices(A, B, R2, rA, cA, rB, cB);
    printf("The Result of multiplication:\n");
    printMatrix(R2, rA, cB);

    freeMatrix(A, rA);
    freeMatrix(B, rB);
    freeMatrix(R1, rA);
    freeMatrix(R2, rA);
    return 0;
}
