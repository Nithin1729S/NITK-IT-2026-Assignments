#include <stdio.h>

int main()
{
    float A, B, C;

    printf("Enter the first angle A: ");
    scanf("%f", &A);

    printf("Enter the second angle B: ");
    scanf("%f", &B);

    C = 180 - (A + B);

    if (C >= 0)
    {

        printf("Third angle C = %.2f\n", C);
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}
