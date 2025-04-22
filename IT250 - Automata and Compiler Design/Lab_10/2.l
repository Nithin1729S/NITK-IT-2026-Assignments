%{
#include "y.tab.h"
%}

%%
p { return 'p'; }
n { return 'n'; }
q { return 'q'; }
\n { return newline; }
. { printf("Invalid String\n"); exit(0); }
%%

int yywrap() {
    return 1;
}

