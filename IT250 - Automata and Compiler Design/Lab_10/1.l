%{
#include "y.tab.h"
%}

%%
p { return 'p'; }
n { return 'n'; }
q { return 'q'; }
\n { return newline; }
. { printf("Invalid Expression\n"); exit(0); }
%%

int yywrap() {
    return 1;
}

