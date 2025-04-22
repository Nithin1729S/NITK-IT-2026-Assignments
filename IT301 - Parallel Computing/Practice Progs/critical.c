#include<stdio.h>
#include<omp.h>
int main()
{
    int b[10]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int sum=0;
    int i;
    int sumLocal;
    #pragma omp parallel shared(b,sum) private(i,sumLocal)
    {
        sumLocal=0;
        #pragma omp for
        for(i =0;i<n;i++) sumLocal+=b[i];
        #pragma omp critical(update_sum)
        {
            sum+=sumLocal;
        }
    }
    printf("%d",sum);
}