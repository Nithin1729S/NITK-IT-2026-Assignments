%{  
 #include<stdio.h>  
 #include<stdlib.h>  
 int yylex();
 int yyerror();
%}  

%token END
%token ID NUM IF ELSE LE GE EQ NE OR AND STMT KEY LT GT
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%left '!'

%%  

S : STS END {printf("\nParsing is Successful\n\n");  exit(0);}
  ;

STS:    IBLK 
       | STS IBLK 
       ;

IBLK: IF '(' exp ')'  '{' BODY '}' EBLK
      | IF '(' exp ')'  EXPR 
      | IF '(' exp ')'  '{' BODY '}' 
      ;

BODY: IBLK EXPR  
      | IBLK
      | EXPR IBLK
      | EXPR 
      ;

EBLK: ELSE EXPR
        | ELSE '{' BODY '}'
        ;


exp  :     exp LE exp
           | exp GE exp
           | exp EQ exp
           | exp NE exp
           | exp OR exp
           | exp LT exp
           | exp GT exp
           | exp AND exp
           | exp '+' exp
           | exp '-' exp
           | exp '*' exp
           | exp '/' exp
           | exp '%' exp
           | '(' exp ')'
           | ID
           | NUM
           ;

EXPR :   STMT



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