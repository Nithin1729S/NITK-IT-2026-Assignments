#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[largest] < A[left])
        largest = left;
    if (right < n && A[largest] < A[right])
        largest = right;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        maxHeapify(A, n, largest);
    }
}

void buildMaxHeap(int A[], int n)
{
    int lastNonLeaf = n / 2 - 1;
    for (int i = lastNonLeaf; i >= 0; i--)
        maxHeapify(A, n, i);
}

void heapSort(int A[], int n)
{
    buildMaxHeap(A, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&A[i], &A[0]);
        n--;
        maxHeapify(A, n, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int) * n);
    printf("Enter the %d elements of the array: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    buildMaxHeap(A,n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    heapSort(A,n);
    printf("The sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}