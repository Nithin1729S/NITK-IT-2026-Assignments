%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int arr[100000];
int size = 0;
int ctr = 0;
%}

%option noyywrap

%%

[ \t]+              
[0-9]+              {arr[ctr++] = atoi(yytext); }
\n                  {break; }
.                   { printf("Invalid\n"); exit(1); }

%%

int main(){
    char charArray1[1024];
    fgets(charArray1, sizeof(charArray1), stdin);
    if (sscanf(charArray1, "%d", &size) != 1 || size <= 0 || size > 100000 || charArray1[strspn(charArray1, "0123456789 \t\n")] != '\0') {
        printf("Invalid\n");
        exit(1);
    }
    fgets(charArray1, sizeof(charArray1), stdin);
    yy_scan_string(charArray1);
    int i, mini = 10000000;
    int maxi=-1000000;
    for (i = 0; i < size; i++) {
        yylex();
        if (arr[i] < mini) {
            mini = arr[i];
        }
    }
    for(i=0;i<size;i++)
    {
    	yylex();
    	if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    printf("\n");
    printf("%d ", mini);
    printf("%d\n",maxi);
    return 0;
}


