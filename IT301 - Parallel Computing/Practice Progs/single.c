#include<stdio.h>
#include<omp.h>
int main()
{
    int a=3;
    int n=10;
    int b[n];
    int i;
    #pragma omp parallel shared(a,b,n) private(i)
    {
        #pragma omp single
        {
            a++;
        }
        #pragma omp for nowait
        for(i=0;i<n;i++)
        {
            b[i]=a;
        }
        
        
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
}