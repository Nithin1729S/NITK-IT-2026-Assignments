#include<stdio.h>
#include<omp.h>
int main()
{
    int x=1;
    printf("%d\n",x);
    #pragma omp parallel num_threads(3) private(x)
    {
        x=10;
        printf("%d\n",x);
    }
    return 0;
}