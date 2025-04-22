#include <stdio.h>
#include<stdlib.h>
#define SIZE 100

int H[100];

char* trim(char *str)
{
    char *trimmed=(char*)malloc(SIZE*sizeof(char));
    int i=0;
    int j=0;
    while(str[i])
    {
        if(str[i]!=' ' && str[i]!='\t'&&str[i]!='\n')
        {
            trimmed[j++]=str[i];
        }
        i++;
    }
    trimmed[j]='\n';
    return trimmed;
}

int main() {
    char *str=(char*)malloc(SIZE*sizeof(char));
    printf("Enter the string: ");
    fgets(str, SIZE, stdin);

    str=trim(str);
    int i=0;
    while(str[i]!='\n')
    {   
        H[str[i]-65]++;
        i++;
    }

    for(int i=0;i<100;i++)
    {
        if(H[i]>1) printf("%c  is repeated %d times\n",i+65,H[i]);
    }
    return 0;
}

