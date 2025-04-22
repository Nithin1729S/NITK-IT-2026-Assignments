#include <stdio.h>
#include <omp.h>

int main() 
{
    int num_procs = omp_get_num_procs();
    printf("Number of processors available: %d\n", num_procs);

    omp_set_num_threads(4);

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 8; i++) {
            int thread_id = omp_get_thread_num();
            printf("Thread %d: Hello World\n", thread_id);
        }
    }

    printf("Number of threads used: %d\n", omp_get_num_threads());

    if (omp_in_parallel()) {
        printf("Currently in a parallel region.\n");
    } else {
        printf("Not in a parallel region.\n");
    }

    int dynamic_enabled = omp_get_dynamic();
    printf("Dynamic threads enabled: %d\n", dynamic_enabled);

    int nested_enabled = omp_get_nested();
    printf("Nested parallelism enabled: %d\n", nested_enabled);

    return 0;
}
