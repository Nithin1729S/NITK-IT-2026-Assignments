#include<stdio.h>
int main()
{
    FILE* ptr=fopen("new.txt","r");
    FILE* ptr1=fopen("temp.txt","w");
    char c;
    while((c=fgetc(ptr))!=EOF)
    {
        fputc(c,ptr1);
    }
    return 0;
}