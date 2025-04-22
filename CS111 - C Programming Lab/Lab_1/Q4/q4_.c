#include <stdio.h>
#include <math.h>

int main()
{
    double number, result;

    printf("Enter a number: ");
    scanf("%lf", &number);

    if (number >= 0)
    {
        result = sqrt(number);
        printf("Square root of %.2lf is %.5lf\n", number, result);
    }
    else
    {
        printf("Invalid input. The number must be non-negative.\n");
    }

    return 0;
}
