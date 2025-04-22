#include<stdio.h>
int main()
{
    FILE *ptr=fopen("virat.txt","r");
    char c;
    int count=1;
    while((c=fgetc(ptr))!=EOF)
    {
        if(c=='\n') count++;
    }
    printf("Number of lines : %d",count);
    return 0;
}