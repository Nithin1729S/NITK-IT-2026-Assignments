#include <stdio.h>
#include <omp.h>

int main(void) {
    int i = 10;
    int num_procs = omp_get_num_procs();
    printf("Number of available processors: %d\n", num_procs);
    omp_set_num_threads(num_procs);
    int is_dynamic = omp_get_dynamic();
    printf("Is dynamic thread adjustment enabled? %d\n", is_dynamic);
    int is_nested = omp_get_nested();
    printf("Is nested parallelism enabled? %d\n", is_nested);
    #pragma omp parallel firstprivate(i)
    {
        if (omp_in_parallel()) {
            printf("In parallel region.\n");
        }
        int thread_num = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Thread %d out of %d threads: i = %d\n", thread_num, num_threads, i);
        i = 1000 + thread_num;
    }
    printf("Value of i after parallel region: %d\n", i);
    return 0;
}
