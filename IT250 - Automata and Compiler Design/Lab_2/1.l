%{
 #include<stdio.h>
 #include <stdbool.h>
 bool flg = false;
 int i=0; 
 int arr[2];
%}

%%
[0-9]+ {arr[i++]=atoi(yytext);
        if (i>=2){
        if(!flg){
        if (arr[0]>arr[1]){
            printf("%d\n", arr[1]);
            printf("Thank you\n");
        }
        else{
            printf("%d\n", arr[1]);
            printf("Sorry\n");
        }
        }
        else {
          arr[1] = atoi(yytext);
          return 0;
        }
        i=0;
        fflush(stdin);
        return 0;       
        }       
    }

[\n\t ' '] {};
.* {
    flg = true;   
    i++; 
    if(i==2){ 
        printf("%s\nInvalid\n", yytext);
        exit(0);
      }  
}
%%
 
int main(){  
    yylex();
    if(flg) printf("%d\nInvalid\n",arr[1]);
    return 0;
}

int yywrap(void){
   return 1;
}