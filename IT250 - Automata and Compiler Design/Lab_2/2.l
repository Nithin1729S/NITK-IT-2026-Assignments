%{
#include<stdio.h>
%}

%%

.*[0-9] {
   printf("-1\n");
   return 0;
}

[A-Z]      {printf("%c",yytext[0]+ 32);}
[a-z]      {printf("%c",yytext[0]- 32);}
[\t\n]      ECHO;
.           ECHO;
fflush(stdin);
return 0;    
%%

int yywrap(void)
{
   return 1;
}

int main()
{
   char input[256];
   scanf("%255[^\n]",input);
   yy_scan_string(input);
   
   yylex();
   printf("\n");
   return 0;
}




