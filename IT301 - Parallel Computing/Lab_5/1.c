#include<stdio.h>
#include<omp.h>

int fibonacci(int n)
{
    if(n<=1) return n;
    int x,y;
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task shared(x)
            {
                x=fibonacci(n-1);
            }
            #pragma omp task shared(y)
            {
                y=fibonacci(n-2);
            }
            #pragma omp taskwait
        }
    }
    return x+y;
}

int main()
{
    int n=15;
    omp_set_num_threads(2);
    double start=omp_get_wtime();
    int result=fibonacci(n);
    double end=omp_get_wtime();
    printf("Fibonacci of %d is %d\n",n,result);
    printf("Time Taken: %f seconds\n",end-start);
    return 0;
}