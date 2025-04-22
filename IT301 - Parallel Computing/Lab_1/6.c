#include<stdio.h>
#include<omp.h>
int main()
{
    #pragma omp parallel num_threads(3)
    {
        printf("Thread ID: %d\n",omp_get_thread_num());
    }
    return 0;
}