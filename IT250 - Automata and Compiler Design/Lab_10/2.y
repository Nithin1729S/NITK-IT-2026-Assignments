%{
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void yyerror(char *);
int yylex(void);
%}

%token p n q newline

%%
line : term newline { printf("Valid String\n"); exit(0); };
term : p power n q { printf("Valid String\n"); exit(0); };
power : n power | n n | n n n | ;
%%

void yyerror(char *msg) {
    printf("Invalid String\n");
    exit(0);
}

int main () {
    printf("Enter the string: ");
    yyparse();
}

