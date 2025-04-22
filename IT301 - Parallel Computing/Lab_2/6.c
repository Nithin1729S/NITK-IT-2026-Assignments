#include <stdio.h>
#include <omp.h>

int main() {
    int i;
    int sum = 0;
    omp_set_num_threads(4);

    
    #pragma omp parallel
    {
        
        #pragma omp for reduction(+:sum)
        for (i = 1; i <= 10; i++) {
            sum += i;
            
            printf("Thread %d: i = %d\n", omp_get_thread_num(), i);
        }
    }
    
    printf("Total sum: %d\n", sum);

    return 0;
}
