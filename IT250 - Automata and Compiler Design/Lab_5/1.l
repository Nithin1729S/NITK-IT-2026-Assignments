%{
#include<stdio.h>  
int i=0; 
%}
%%
"//".*\n            {  }   //for single line comments
"/*"[^*/]*"*/"      { }    //for multi line comments
.  {
    if(!i)
    {
        printf("\n");
        printf("\n");
        printf("Output:\n\n");
        i=1;
    } 
    ECHO; }
%%
int main(int argc, int **argv)
{
    printf("Enter Code:\n\n");
    yylex();
    printf("\n");
    return 0;
}

int yywrap(void) {
	return 1;
}


