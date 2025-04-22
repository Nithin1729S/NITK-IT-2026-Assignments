%{
#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
float n;
int track=0;
int accepted = 0;
int rejected = 0;
char array[100];
%}

%%

[01]+ {
    int zeroCount = 0, oneCount = 0;
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '0') {
            zeroCount++;
        }
        else oneCount++;
    }
    if (oneCount % 2 == 1 && zeroCount % 2 == 0) {
        array[track++]='A';
        //printf("A ");
        accepted++;
    }
    else {
        array[track++]='R';
        //printf("R ");
        rejected++;
    }
}

[0-9]+\.[0-9]+ {printf("-2\n"); exit(0);}

.* {//printf("I ");
    array[track++]='I';}

%%


int yywrap(void){
    return 1;
}

bool hasDecimal(float f) {
    return (f-(int)f != 0);
}

int main(){
    scanf("%f", &n);
    if(hasDecimal(n))
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        char input[100];
        scanf("%s", input);
        yy_scan_string(input);
        yylex();
    }
    for(int i=0;i<track;i++)
    {
        printf("%c ",array[i]);
    }
    printf("\n");
    printf("%d %d", accepted, rejected);
    printf("\n");
    return 0;
}





