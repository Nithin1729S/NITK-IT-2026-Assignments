
%{ 

#include<stdio.h> 
#include<stdlib.h> 
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


[0-9]+ {num=atoi(yytext);   //accepts valid input

	if(num<0)    //to check for negative inputs
	{
		printf("Invalid Input\n");
		return 0;
	}
	if(num==2) 
		{ 
		printf("Prime number\n"); 
		} 
	else if(num==0 || num==1) 
		{ 
		printf("Not a Prime number\n"); 
		} 
	else
	
	
	{ //logic to check prime
	for(j=2;j<num;j++) 
	{ 
		if(num%j==0) 
		flag=1; 
	} 
		if(flag==1) 
		printf("Not a prime number\n"); 
		else if(flag==0) 
		printf("Prime number\n"); 
	}
	flag=0; //reset flag
	fflush(stdin);  //flush input buffer
    	return 0;  //exit program after one input
	} 
%% 


int main() 
{ 
printf("Enter a number:\n");
yylex(); 
return 0; 
} 

