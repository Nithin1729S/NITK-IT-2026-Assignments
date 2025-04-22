#include<stdio.h>
#include<omp.h>
int main()
{
    int isParallel=1;
    #pragma omp parallel if(isParallel==1) num_threads(4)
    {
        printf("Hello\n");
    }
    return 0;
}