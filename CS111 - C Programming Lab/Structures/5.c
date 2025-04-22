#include <stdio.h>

struct distance
{
    int feet;
    float inch;
};

struct complexNum
{
    float real;
    float imag;
};

struct Time
{
    int hrs;
    int mins;
    int secs;
};

struct distance addDistance(struct distance dist1, struct distance dist2)
{
    struct distance res;
    res.feet = dist1.feet + dist2.feet;
    res.inch = dist1.inch + dist2.inch;

    if (res.inch >= 12.0)
    {
        res.feet += (int)(res.inch / 12);
        res.inch = res.inch - 12 * (int)(res.inch / 12);
    }
    return res;
}

struct complexNum addComplx(struct complexNum c1, struct complexNum c2)
{
    struct complexNum res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;

    return res;
}

struct Time diffTime(struct Time t1, struct Time t2)
{
    struct Time res;
    int totalSecs1 = t1.secs + t1.hrs * 3600 + t1.mins * 60;
    int totalSecs2 = t2.secs + t2.hrs * 3600 + t2.mins * 60;
    int diff = totalSecs1 - totalSecs2;

    res.hrs = diff / 3600;
    res.mins = (diff % 3600) / 60;
    res.secs = diff % 60;
    return res;
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Add two distances\n");
        printf("2. Add two complex numbers\n");
        printf("3. Calculate the difference between two time periods\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            struct distance distance1, distance2, result;
            printf("Enter first distance (feet inch): ");
            scanf("%d %f", &distance1.feet, &distance1.inch);
            printf("Enter second distance (feet inch): ");
            scanf("%d %f", &distance2.feet, &distance2.inch);

            result = addDistance(distance1, distance2);

            printf("Sum of distances: %d feet %.2f inches\n", result.feet, result.inch);
            break;
        }
        case 2:
        {
            struct complexNum complex1, complex2, result;
            printf("Enter first complex number (real imag): ");
            scanf("%f %f", &complex1.real, &complex1.imag);
            printf("Enter second complex number (real imag): ");
            scanf("%f %f", &complex2.real, &complex2.imag);

            result = addComplx(complex1, complex2);

            printf("Sum of complex numbers: %.2f + %.2fi\n", result.real, result.imag);
            break;
        }
        case 3:
        {
            struct Time time1, time2, result;
            printf("Enter first time period (hours minutes seconds): ");
            scanf("%d %d %d", &time1.hrs, &time1.mins, &time1.secs);
            printf("Enter second time period (hours minutes seconds): ");
            scanf("%d %d %d", &time2.hrs, &time2.mins, &time2.secs);

            result = diffTime(time1, time2);

            printf("Time difference: %d hours %d minutes %d seconds\n", result.hrs, result.mins, result.secs);
            break;
        }
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
