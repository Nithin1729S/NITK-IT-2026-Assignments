#include<stdio.h>
#include<omp.h>
int main()
{
    printf("Before: Total no of threads: %d\n",omp_get_num_threads());
    #pragma omp parallel
    {
        printf("Thread id is %d\n",omp_get_thread_num());
    }
    printf("After: Total no of threads: %d\n",omp_get_num_threads());
    return 0;
}