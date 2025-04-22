#include <iostream>
#include <climits> 
#include <cstdlib> 
#include <ctime>   

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l]; 
    int i = l, j = h;
    
    do {
        do {i++;} while (A[i] <= pivot);
        do {j--;} while (A[j] > pivot);
        
        if (i < j)
            swap(&A[i], &A[j]);
    } while(i < j);
    
    swap(&A[l], &A[j]); 
    
    return j;
}

int randomizedPartition(int A[], int l, int h) {
    int randomIndex = l + rand() % (h - l); 
    swap(&A[l], &A[randomIndex]); 
    return partition(A, l, h);
}





void quickSort(int A[], int l, int h) {
    if (l < h) {
        int j = randomizedPartition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

int main() {
    srand(time(0)); 

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX}; 
    int n = 11;
    
    quickSort(A, 0, n-1);
    
    for (int i = 0; i < n-1; i++)
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}
