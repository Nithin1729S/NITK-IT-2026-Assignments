#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void toLower(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+('a'-'A');
        }
        i++;
    }
    
}
int main()
{
    char*str=(char*)malloc(sizeof(char)*SIZE);
    printf("Enter the string: ");
    scanf("%[^\n]%*c",str);
    //fgets(str,SIZE,stdin);
    toLower(str);
    printf("%s",str);
    return 0;


}