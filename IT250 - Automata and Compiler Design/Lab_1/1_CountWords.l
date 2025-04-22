%{
#include<stdio.h>
#include<string.h>
int count = 0;
%}

%%

[0-9]+ {
    printf("Invalid Input\n");  
}

([a-zA-Z][a-zA-Z0-9]*) {
    count++;
}

"\n" {
    if(count>0) printf("%d\n", count);
    count = 0;
    fflush(stdin);  //flush input buffer
    return 0;  //exit program after one input
}

%%



int main()
{
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}

