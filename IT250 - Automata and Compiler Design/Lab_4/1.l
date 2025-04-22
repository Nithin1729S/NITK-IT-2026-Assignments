%{
#include <stdio.h>
int keywords = 0;
int numbers = 0;
int identifiers = 0;
int operators = 0;
int puncutations = 0;
int ignore = 0;
int newline = 0;
%}

%%

(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)[ \t]+ {keywords++;}

[0-9]+[ \t]+ {numbers++;}

[0-9]+[a-zA-Z_0-9]*[ \t]+ {ignore++;}

[a-zA-Z_][a-zA-Z0-9_]*[ \t]+ {identifiers++;}

[+|-|*|/|>|<|>=|<=|==|!=][ \t]+ {operators++;}

[{}().,;:%&|^!~=<>?][ \t]+ {puncutations++;}

[\n] {newline++;}

. {ignore++;}


%%
int yywrap(void){
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return -1;
    }
    fseek(fp,0,SEEK_SET);
    yyin = fp;

    yylex();
    
    fclose(fp);

    printf("\nNumber of Keywords: %d", keywords);
    printf("\nNumber of Numbers: %d", numbers);
    printf("\nNumber of Identifiers: %d", identifiers);
    printf("\nNumber of Operators: %d", operators);
    printf("\nNumber of Puncutations: %d", puncutations);
    printf("\nTotal Number of Tokens are: %d\n", keywords + numbers + identifiers + operators + puncutations);

    return 0;
}






