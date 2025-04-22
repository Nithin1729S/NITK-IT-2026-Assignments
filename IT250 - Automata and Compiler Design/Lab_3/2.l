%{
#include <stdio.h>
#include<string.h>
int mini = -1;  
char shortest[100];
int track=0;
%}

%%
([a-b]*[^a-b \n\t]+[a-b]*)+  {
    printf("-2 ");   
}

(b(ab)*a?|a(ba)*b?) {
    if(mini == -1) mini = yyleng;
    else if (yyleng < mini) {
        mini = yyleng;
        strncpy(shortest,yytext,yyleng);
        shortest[yyleng]='\0';

    }
    printf("1");    
}

[ab]+ {
    if(mini == -1||yyleng<mini)
    {
        mini = yyleng;
        strncpy(shortest,yytext,yyleng);
        shortest[yyleng]='\0';
    } 
    
    printf("-1");   
}


[\n] {
    if(mini==-1)
         printf("\n");
    else
    {
        printf("\n%s ",shortest);  
        printf("%d\n", mini);
        

    }
        
    
    return 0;
}

%%


int yywrap(){
    return 1;
}

int main(){  

    yylex(); 
    
    return 0;
}




