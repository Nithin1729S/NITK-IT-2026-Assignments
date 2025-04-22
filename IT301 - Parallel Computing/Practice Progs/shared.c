#include<stdio.h>
#include<omp.h>
int main()
{
    int x=10;
    printf("%d\n",x);
    #pragma omp parallel num_threads(3) shared(x)
    {
        x=15;
        x++;  
        printf("%d\n",x);
    }
    return 0;
}