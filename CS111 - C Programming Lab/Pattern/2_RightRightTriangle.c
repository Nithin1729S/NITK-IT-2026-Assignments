#include<stdio.h>
int main()
{
    int rows=5;
    for(int i=rows;i>0;i--)
    {
        for(int j=rows;j>i;j--) printf(" ");
        for(int j=0;j<i;j++) printf("*");
        printf("\n");
    }
}

