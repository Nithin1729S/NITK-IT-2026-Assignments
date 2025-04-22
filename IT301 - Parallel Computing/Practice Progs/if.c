#include<stdio.h>
#include<omp.h>
int main()
{
    int par=1;
    #pragma omp parallel if(par==1) num_threads(4)
    printf("Hello World\n");
    return 0;
}