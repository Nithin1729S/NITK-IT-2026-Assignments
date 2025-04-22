#include<stdio.h>
#include<omp.h>
int main()
{
    int tid;
    #pragma omp parallel private(tid)
    {
        tid=omp_get_thread_num();
        printf("Thread no %d from total %d threads\n",tid,omp_get_num_threads());
    }
    return 0;

}