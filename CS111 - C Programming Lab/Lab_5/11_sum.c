#include <stdio.h>


unsigned long long factorial(int num) {
    unsigned long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}


double sumOfSeries() {
    double sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        sum += (double)factorial(i) / i;
    }
    return sum;
}

int main() {
    double result = sumOfSeries();

    printf("Sum of the series: %.2f\n", result);

    return 0;
}
