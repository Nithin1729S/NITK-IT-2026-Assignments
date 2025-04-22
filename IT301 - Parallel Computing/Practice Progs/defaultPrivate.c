#include<stdio.h>
#include<omp.h>
int main()
{
    omp_set_num_threads(6);
    int val=0;
    #pragma omp parallel default(none) private(val)
    {
        if(omp_get_thread_num()==0){
            val=123;
        }
        #pragma omp barrier
        if(omp_get_thread_num()==0)
        {
            printf("%d\n",val);
        }

        if(omp_get_thread_num()==2){
            printf("%d\n",val);
        }
    }
    return 0;
}