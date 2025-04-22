#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeapify(int A[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && A[largest]<A[left]) largest=left;
    if(right<n&&A[largest]<A[right]) largest=right;
    if(largest!=i)
    {
        swap(&A[i],&A[largest]);
        maxHeapify(A,n,largest);
    }

}

void buildMaxHeap(int A[],int n)
{
    int lastNonLeaf=n/2-1;
    for(int i=lastNonLeaf;i>=0;i--) maxHeapify(A,n,i);
}

void insert(int A[],int *n,int item)
{
    (*n)++;
    int i=*n-1;
    A[i]=item;
    while (i > 0 && A[(i - 1) / 2] < A[i])
    {
        swap(&A[i], &A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(int A[],int *n)
{

    if(*n<=0) return -1;
    if(*n==1)
    {
        
        int x=A[0];
        *n--;
        return x;
    } 
    int max=A[0];
    A[0]=A[*n-1];
    (*n)--;
    maxHeapify(A,*n,0);
    return max;
}

void increaseKey(int A[], int index, int newValue) {
    if (newValue < A[index]) {
        printf("New value is smaller than the current value. Cannot increase key.\n");
        return;
    }

    A[index] = newValue;

    // Use MAX-HEAPIFY to restore the max-heap property
    maxHeapify(A, index + 1, index);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int *A=(int*)malloc(sizeof(int)*n);
    printf("Enter the %d elements of the array: ",n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    printf("Max Heap: ");
    buildMaxHeap(A,n);
    for(int i=0;i<n;i++) printf("%d ",A[i]);
    printf("\n");

    int choice, item;
    while (1) {
        printf("Choose operation:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insert(A, &n, item);
                printf("Inserted %d.\n", item);
                printf("The Array now is: ");
                for (int i = 0; i < n; i++) printf("%d ", A[i]);
                break;

            case 2:
                item = extractMax(A, &n);
                if (item == -1) {
                    printf("Priority queue is empty.\n");
                } else {
                    printf("Extracted Max: %d\n", item);
                }
                printf("The Array now is: ");
                for (int i = 0; i < n; i++) printf("%d ", A[i]);
                break;

            case 3:
                free(A);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}