
%{ 
#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
int flag,num,j; 
int validNum=0;
%} 


%% 

([a-zA-Z][a-zA-Z0-9]*) {   
    printf("Invalid Input\n");
    return 0;
}

^[-]?[0-9]*[.][0-9]+$ {     //to check for decimmal inputs 
    validNum++;
    if(validNum>0)
	{
		printf("Invalid Input\n");
		return 0;
	}
}

[0-9]+ {num=atoi(yytext); 
	int original = num;
    	int num_digits = 0;
    	int sum = 0;

    
    while (original != 0) {
        original /= 10;
        num_digits++;
    }

    original = num;

    
    while (original != 0) {
        int digit = original % 10;
        sum += pow(digit, num_digits);
        original /= 10;
    }

    if (sum == num) printf("Its a armstrong Number\n");
    else printf("Not a Armstrong Number\n");
    flag=0;
    fflush(stdin);
    return 0;
} 
%% 


int main() 
{ 
printf("Enter a number:\n");
yylex(); 
return 0; 
} 

