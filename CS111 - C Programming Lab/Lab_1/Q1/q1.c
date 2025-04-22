#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);
    printf("Before swapping:\n");
    printf("a = %.2f, b = %.2f\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping:\n");
    printf("a = %.2f, b = %.2f\n", a, b);
    return 0;
}
