#include <stdio.h>
#include <omp.h>

void generate_fibonacci(long long n, long long fib[]) {
    fib[0] = 0;
    fib[1] = 1;

    for (long long i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void print_fibonacci(long long n, long long fib[]) {
    for (long long i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");
}

int main() {
    long long n;
    int num_threads;

    printf("Enter the number of Fibonacci terms: ");
    scanf("%lld", &n);
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    omp_set_num_threads(num_threads);

    long long fib[n];

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            generate_fibonacci(n, fib);
        }   
        #pragma omp section
        {
            #pragma omp critical
            {
                print_fibonacci(n, fib);
            }
        }
    }

    return 0;
}
