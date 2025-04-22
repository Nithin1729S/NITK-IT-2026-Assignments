#include <omp.h>
#include <stdio.h>

int main() {
    int i;
    int sum = 0;

    #pragma omp parallel for lastprivate(sum)
    for (i = 0; i < 10; i++) {
        sum = i;
        printf("Thread %d: i = %d, sum = %d\n", omp_get_thread_num(), i, sum);
    }

    printf("After parallel region: sum = %d\n", sum);
    return 0;
}
