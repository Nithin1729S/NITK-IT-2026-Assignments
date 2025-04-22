#include<stdio.h>
#include<omp.h>
int main()
{
    int x=1;
    printf("%d\n",x);
    #pragma omp parallel num_threads(3) private(x)
    {
        printf("%d\n",x);  //garbage printed if private x not intialized
    }
    return 0;
}