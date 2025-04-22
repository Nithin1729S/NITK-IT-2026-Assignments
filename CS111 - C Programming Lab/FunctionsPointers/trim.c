#include <stdio.h>
#include<stdlib.h>
#define SIZE 1000


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
    char sentence[SIZE];
    printf("Enter a sentence: ");
    fgets(sentence, SIZE, stdin);

    printf("String after removing spaces: %s\n", trim(sentence));

    return 0;
}
