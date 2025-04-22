%{
#include "y.tab.h"
#include <string.h>
%}

%%
[ \t\n]
    "while" return WHILE;
    "do" return DO;
    "print" return PRINT;
    "or" return OR;
    "and" return AND;
[0-9]+ {
    strcpy(yylval.str, yytext);
    return NUM;
}
[A-Za-z]([A-Za-z]|[0-9])* {
    strcpy(yylval.str, yytext);
    return ID;
}
"(" return OP;
")" return CP;
"<=" return LE;
">=" return GE;
"==" return EQ;
"!=" return NE;
[ \n]+ {}
. {
    return yytext[0];
}
"----" return STMT;
"$\n" return END;
%%

int yywrap() {
    return 0;
}
