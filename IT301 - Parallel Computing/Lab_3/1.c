#include <omp.h>
#include <stdio.h>

int main() {
    int x = 10;
    #pragma omp parallel default(shared)
    {
        int tid = omp_get_thread_num();
        printf("Thread %d: x = %d\n", tid, x);
    }
    #pragma omp parallel default(none) private(x)
    {
        int tid = omp_get_thread_num();
        x = tid;  // each thread has its own x
        printf("Thread %d: x = %d\n", tid, x);
    }

    return 0;
}
