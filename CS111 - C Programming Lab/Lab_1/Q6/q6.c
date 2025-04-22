#include <stdio.h>

int main()
{
    int n;
    int last = 0;
    int rev = 0;
    printf("Enter a 5-digit number: ");
    scanf("%d", &n);
    {
        last = n % 10;
        rev = rev * 10 + last;
        n = n / 10;
    }

    {
        last = n % 10;
        rev = rev * 10 + last;
        n = n / 10;
    }

    {
        last = n % 10;
        rev = rev * 10 + last;
        n = n / 10;
    }
    {
        last = n % 10;
        rev = rev * 10 + last;
        n = n / 10;
    }
    {
        last = n % 10;
        rev = rev * 10 + last;
        n = n / 10;
    }
    printf("Reversed Number = %d\n", rev);
    return 0;
}
