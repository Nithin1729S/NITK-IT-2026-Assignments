%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyparse();
int yyerror();
%}

%token END
%token ID NUM WHILE LE GE EQ NE OR AND STMT OP CP DO KEY LT GT
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%left '!'

%%

S : OPTIONA END {printf("\nParsing is Successful\n\n"); exit(0);}
  | OPTIONB END {printf("\nParsing is Successful\n\n"); exit(0);}
  ;
OPTIONA: BLK
           | OPTIONA BLK
           ;
OPTIONB: DO '{' BODY '}' WHILE '(' COND ')' ';'
           ;
BLK: WHILE '(' COND ')' '{' BODY '}'
	| WHILE '(' COND ')'
	| WHILE '(' COND ')' STMT
	| WHILE '(' COND ')' BLK
	;
BODY: BLK
	|OPTIONB
	|STMT
	|STMT BLK
	|STMT BLK STMT
	|BLK STMT
	|STMT OPTIONB
	|STMT OPTIONB STMT
	|OPTIONB STMT
	;
	
COND : COND LE COND
	| COND GE COND
	| COND EQ COND
	| COND NE COND
	| COND OR COND
	| COND LT COND
	| COND GT COND
	| COND AND COND
	| COND '+' COND
	| COND '-' COND
	| COND '*' COND
	| COND '/' COND
	| COND '%' COND
	| '(' COND ')'
	| ID
	| NUM
	;
	
EXPR : STMT

%%

int main()
{
printf("\nEnter the expression:\n\n");
yyparse();
return 0;
}
int yyerror()
{
printf("\nParsing is Failed\n\n");
return 0;
}
