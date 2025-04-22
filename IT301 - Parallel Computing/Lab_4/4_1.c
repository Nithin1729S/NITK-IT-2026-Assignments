#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int tid, x;
#pragma omp threadprivate(x, tid)

void main() {
    x = 10;

    #pragma omp parallel num_threads(4)
    {
        tid = omp_get_thread_num();
        
        #pragma omp master
        {
            printf("Parallel region 1 \n");
            x = x + 1;
        }

        #pragma omp barrier
        
        if (tid == 1)
            x = x + 2;

        printf("thread %d value of x is %d\n", tid, x);
    }

    #pragma omp parallel num_threads(4)
    {
        #pragma omp master
        {
            printf("Parallel region 2 \n");
        }

        #pragma omp barrier
        
        printf("thread %d value of x is %d\n", tid, x);
    }

    printf("value of x in main region is %d\n", x);
}
