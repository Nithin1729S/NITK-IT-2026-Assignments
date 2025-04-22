%{
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void yyerror(char *);
int yylex(void);
%}

%token p n q newline

%%
line : term newline { printf("Sequence Accepted\n"); exit(0); };
term : p power n q { printf("Sequence Accepted\n"); exit(0); };
power : n power | n n | ;
%%

void yyerror(char *msg) {
    printf("Invalid Expression\n");
    exit(0);
}

int main () {
    printf("Enter the string: ");
    yyparse();
}

