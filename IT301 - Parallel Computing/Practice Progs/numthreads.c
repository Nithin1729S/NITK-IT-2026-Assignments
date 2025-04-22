#include<stdio.h>
#include<omp.h>
int main()
{
    int par=0;
    #pragma omp parallel if(par==0) num_threads(6)
    printf("Hello");
    return 0;
}