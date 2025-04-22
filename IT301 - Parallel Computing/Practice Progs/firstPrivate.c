#include<stdio.h>
#include<omp.h>
int main()
{
    int x=10;
    omp_set_num_threads(3);
    #pragma omp parallel firstprivate(x)
    {
        x++;
        printf("%d\n",x);
    }
    return 0;
}