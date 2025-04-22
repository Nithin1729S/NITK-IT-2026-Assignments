#include<stdio.h>

double fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}
double sum(int n)
{
    if(n<0) return 0;
    int num=2*n+1;
    return 1.0/fact(num) + sum(n-1);

}

int main()
{
    int n=2;
    printf("%lf",sum(n));
}