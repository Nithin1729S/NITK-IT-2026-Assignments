#include<stdio.h>
#include<omp.h>
int main()
{
    #pragma omp parallel
    {
        #pragma omp for ordered
        for(int i=0;i<10;i++)
        {
            #pragma omp ordered
            printf("%d is executing iteration %d\n",omp_get_thread_num(),i);
        }
    }
}