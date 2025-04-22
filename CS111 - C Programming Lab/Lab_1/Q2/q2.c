#include <stdio.h>
int main()
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Decimal value: %d\nOctal value: %o\nHexadecimal value: %x\n", c, c, c);
    return 0;
}
