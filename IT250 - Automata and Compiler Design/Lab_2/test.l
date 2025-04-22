%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int arr[100000];
int size = 0;
int idx = 0;
%}

%option noyywrap

%%

[ \t]+              
[0-9]+              {arr[idx++] = atoi(yytext); }
\n                  {break; }
.                   { printf("Invalid\n"); exit(1); }

%%

int main(){
    char String[1024];
    fgets(String, sizeof(String), stdin);
    if (sscanf(String, "%d", &size) != 1 || size <= 0 || size > 100000 || String[strspn(String, "0123456789 \t\n")] != '\0') {
        printf("Invalid\n");
        exit(1);
    }
    fgets(String, sizeof(String), stdin);
    yy_scan_string(String);
    int i, minValue = 10000000;
    int maxValue=-1000000;
    for (i = 0; i < size; i++) {
        yylex();
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    for(i=0;i<size;i++)
    {
    	yylex();
    	if(arr[i]>maxValue)
        {
            maxValue=arr[i];
        }
    }
    printf("\n");
    printf("%d ", minValue);
    printf("%d\n",maxValue);
    return 0;
}


