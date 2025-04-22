%{
#include <stdio.h>
int flag = 0;
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4} { flag = 1; }
.|\n {}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter Email Id: ");
    char input[256];
    scanf("%s",input);
    yy_scan_string(input);
    yylex();
    if (flag == 1)
        printf("Valid Email Id\n");
    else
        printf("Not Valid Email Id\n");
    return 0;
}
