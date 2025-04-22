%{
#include<stdio.h>
#include<stdlib.h>
int valid=0;
%}
letter	[a-z|A-Z]
digit	[0-9]
protocol	["http://"|"https://"|""]
domainname	[".org"|".in"|"com"|".net"]
character	['_'|'*'|'$'|'#']
%%
{protocol}?+"www."+({letter}|{digit}|{character})({letter}|{digit}|{character})*+{domainname} { valid=1;}
"\n" {
    if(valid==1)
        printf("\nValid URL\n");
    else
        printf("\nInvalid URL\n");
    exit(0);
}
%%
int main()
{
    printf("Enter URL: ");
    yylex();
    return 0;
}
int yywrap(void) {
	return 1;
}




