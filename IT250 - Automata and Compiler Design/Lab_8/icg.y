%{
#include <stdio.h>
#include <string.h>

int countline = 1;
int countvar = 0;
char ir[2000];
int stack[100];
int top = 0;
%}

%union {
    char str[2000];
}

%token END
%token ID NUM WHILE LE GE EQ NE OR AND STMT OP CP DO PRINT
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%left '!'
%right UMINUS
%type <str> EXPRN
%type <str> EXPRNS
%type <str> WBCK
%type <str> CODE
%type <str> S
%type <str> WBDY
%type <str> WSTMNT
%type <str> NUM
%type <str> ID

%%

S : CODE END {
    sprintf(ir, "%s", $1);
    return 0;
}
;

CODE: WBCK {
    sprintf($$, "%s", $1);
}
| EXPRNS ';' {
    sprintf($$, "%s", $1);
}
| CODE CODE {
    sprintf($$, "%s\n%s", $1, $2);
}
;

WBCK: WSTMNT '{' WBDY '}' {
    sprintf($$, "%s %d\n%s\ngoto %d", $1, countline + 1, $3, stack[--top]);
    countline++;
}
| WSTMNT ';' {
    sprintf($$, "%s %d\ngoto %d", $1, countline + 1, stack[--top]);
    countline++;
}
| WSTMNT EXPRN ';' {
    sprintf($$, "%s %d\n%s\ngoto %d", $1, countline + 1, ir, stack[--top]);
    sprintf(ir, "\0");
    countline++;
}
| WSTMNT WBCK {
    sprintf($$, "%s %d\n%s\ngoto %d", $1, countline + 1, $2, stack[--top]);
    countline++;
}
| WSTMNT '{' '}' {
    sprintf($$, "%s %d\ngoto %d", $1, countline + 1, stack[--top]);
}
;

WSTMNT: WHILE OP EXPRN CP {
    int irStartLine = countline - 1;
    for (int i = 0; i < strlen(ir); i++) {
        if (ir[i] == '\n') {
            irStartLine--;
        }
    }
    if (ir[0] == '\0') irStartLine = countline;
    sprintf($$, "%s\nif(%s == 0) goto ", ir, $3);
    sprintf(ir, "\0");
    if ($$[0] == '\n') {
        for (int i = 0; i < strlen($$); i++) {
            $$[i] = $$[i + 1];
        }
    }
    stack[top] = irStartLine;
    top++;
    countline++;
}
;

EXPRNS: EXPRN {
    $$[0] = '\0';
    sprintf($$, "%s", ir);
    sprintf(ir, "\0");
}
| PRINT EXPRN {
    sprintf($$, "print %s", $2);
    countline++;
}
| EXPRNS ';' EXPRN {
    sprintf($$, "%s\n%s", $1, ir);
    sprintf(ir, "\0");
}
| EXPRNS ';' PRINT EXPRN {
    sprintf($$, "%s\n%sprint %s", $1, ir, $4);
    sprintf(ir, "\0");
    countline++;
}
;

WBDY: WBCK {
    sprintf($$, "%s", $1);
}
| EXPRNS ';' {
    sprintf($$, "%s", $1);
}
| WBDY WBDY {
    sprintf($$, "%s\n%s", $1, $2);
}
;

EXPRN: EXPRN '+' EXPRN {
    sprintf(ir, "%s\nt%d = %s + %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| '-' EXPRN %prec UMINUS {
    sprintf(ir, "%s\nt%d = uminus %s", ir, countvar, $2);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    countvar++;
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countline++;
}
| EXPRN '*' EXPRN {
    sprintf(ir, "%s\nt%d = %s * %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN '-' EXPRN {
    sprintf(ir, "%s\nt%d = %s - %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    countvar++;
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countline++;
}
| EXPRN '/' EXPRN {
    sprintf(ir, "%s\nt%d = %s / %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN '<' EXPRN {
    sprintf(ir, "%s\nt%d = %s < %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN '>' EXPRN {
    sprintf(ir, "%s\nt%d = %s > %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN '=' EXPRN {
    sprintf(ir, "%s\n%s = %s", ir, $1, $3);
    $$[0] = '\0';
    sprintf($$, "%s", $1);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countline++;
}
| EXPRN OR EXPRN {
    sprintf(ir, "%s\nt%d = %s or %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN AND EXPRN {
    sprintf(ir, "%s\nt%d = %s and %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| '!' EXPRN {
    sprintf(ir, "%s\nt%d = !%s", ir, countvar, $2);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN GE EXPRN {
    sprintf(ir, "%s\nt%d = %s >= %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN EQ EXPRN {
    sprintf(ir, "%s\nt%d = %s == %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN NE EXPRN {
    sprintf(ir, "%s\nt%d = %s != %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| EXPRN LE EXPRN {
    sprintf(ir, "%s\nt%d = %s <= %s", ir, countvar, $1, $3);
    $$[0] = '\0';
    sprintf($$, "t%d", countvar);
    if (ir[0] == '\n') {
        for (int i = 0; i < strlen(ir); i++) {
            ir[i] = ir[i + 1];
        }
    }
    countvar++;
    countline++;
}
| OP EXPRN CP {
    $$[0] = '\0';
    sprintf($$, "%s", $2);
}
| NUM {
    sprintf($$, "%s", $1);
}
| ID {
    sprintf($$, "%s", $1);
}
;

%%

int yyerror() {
    printf("\nParsing is failed.\n");
    return 0;
}

int main() {
    ir[0] = '\0';
    stack[0] = 1;
    yyparse();
    countline = 2;
    printf("1. ");
    for (int i = 0; i < strlen(ir); i++) {
        if (ir[i] == '\n') {
            printf("\n%d. ", countline);
            countline++;
        } else
            printf("%c", ir[i]);
    }
    printf("\n");
    return 0;
}
