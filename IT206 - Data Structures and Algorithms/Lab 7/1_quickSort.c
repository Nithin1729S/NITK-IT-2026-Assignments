#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l;
    int j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    QuickSort(arr, 0, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}
