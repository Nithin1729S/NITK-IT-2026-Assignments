#include<stdio.h>
#include<omp.h>

int main()
{
    int arr[3] = {0, 9, 0}; 
    int i;
    int n = 3;

    #pragma omp parallel for shared(arr,n) private(i)  //without for each thread executes this 3 times
    for(i = 0; i < n; i++){
        arr[i] = i + n;
        printf("Thread %d is executing\n", omp_get_thread_num()); 
    }


    printf("Updated array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
