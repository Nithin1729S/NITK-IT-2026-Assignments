#include <stdio.h>
#include <omp.h>

int main() {
    int sharedVar=0;
    #pragma omp parallel shared(sharedVar)
    {
        #pragma omp critical
        {
            printf("Thread no %d : sharedVar = %d\n",omp_get_thread_num(),sharedVar++);
        }
    }

    return 0;
}
