#include<stdio.h>
#include<omp.h>
int main()
{
    int tid;
    int pVar;
    #pragma omp parallel private(tid,pVar)
    {
        tid=omp_get_thread_num();
        pVar=0;
        if(tid==0){
            pVar++;
        }
        printf("Thread no %d: pVar is %d\n",tid,pVar);
    }
    return 0;

}