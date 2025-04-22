#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(void)
{
    int i;
    #pragma omp parallel num_threads(4)
    {
    #pragma omp for schedule(static, 5) private(i)
        for (i = 0; i < 25; i++)
        {
            printf("tid=%d, i=%d\n", omp_get_thread_num(), i);
        }
    }
    return 0;
}