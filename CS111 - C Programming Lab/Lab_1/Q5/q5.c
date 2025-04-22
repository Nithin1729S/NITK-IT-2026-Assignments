#include <stdio.h>
#include <math.h>
#define PI 3.142

int main()
{
    double side1, side2, angle_degrees;
    double area;

    printf("Enter the length of side 'a': ");
    scanf("%lf", &side1);

    printf("Enter the length of side 'b': ");
    scanf("%lf", &side2);

    printf("Enter the angle 'C' in degrees: ");
    scanf("%lf", &angle_degrees);

    double angle_radians = angle_degrees * PI / 180.0;

    area = (0.5) * side1 * side2 * sin(angle_radians);

    printf("Area of the scalene triangle = %.2lf square units\n", area);

    return 0;
}

