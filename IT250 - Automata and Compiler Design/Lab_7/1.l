%{
#include "y.tab.h"
extern int yylval;
%}

%%

[\t \n]         /* Skip whitespace and newline characters */
if              { return IF; }
else            { return ELSE; }
[0-9]+          { return NUM; }
[A-Za-z_]+      { return ID; }
[char|short|int|long|float|double|bool|void|wchar_t|signed|unsigned] { return KEY; }
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"||"            { return OR; }
"&&"            { return AND; }
">"             { return GT; }
"<"             { return LT; }
"//code"        { return STMT; }
.               { return yytext[0]; } /* Return any other character */
"$\n"           { return END; }      /* Return end of input */

%%

int yywrap() {
    return 1;
}
