%{
#include <stdio.h>
#include <string.h>
int n;
int matches = 0;
char K[11];
int flag = 0;
%}


%%

[a-zA-Z_]+ {
    if (strstr(yytext, K) != NULL) {
        matches++;
    }
}

[#]+ {flag = 1;}

%%

int yywrap(void){
    return 1;
}


int main() 
{
    void solution(char K[11], char input[1000], char comments[100][1000]){
        yy_scan_string(input);
        yylex();
        return ;
    }

    char comments[100][1000];
    char line[1000];
    scanf("%d", &n);
    scanf("%s", K);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", line);
        sscanf(line, "%[^\n]", comments[i]);
        solution(K, comments[i], comments);
    }
    if (flag == 1) printf("\n-1\n\n");
    else printf("\n%d\n\n", matches);
    return 0;
}