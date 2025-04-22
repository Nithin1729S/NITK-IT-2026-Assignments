#include<stdio.h>
#include<string.h>


int isPalindrome(char* str,int start, int end)
{
    if(start>=end) return 1;
    if(str[start]!=str[end]) return 0;
    return isPalindrome(str,start+1,end-1);
}
int main()
{
    char str[100]="daddy";
    int start=0;
    int end=strlen(str)-1;
    if(isPalindrome(str,start,end)==1) printf("It is a Palindrome.");
    else printf("It is not a palindrome.");
    return 0;
}