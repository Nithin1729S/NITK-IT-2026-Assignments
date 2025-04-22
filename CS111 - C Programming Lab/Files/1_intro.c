#include<stdio.h>

int main()
{
    FILE* ptr=fopen("new.txt","r+");
    char str[100]="Hi There Hello";
    fputs(str,ptr);
    char str1[100];
    fseek(ptr,0,0);
    fgets(str1,sizeof(str1),ptr);
    printf("%s",str1);
    return 0;


}