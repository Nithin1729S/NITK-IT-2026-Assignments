#include <stdio.h>
#include <omp.h>

void main() {
    int var =98;

    #pragma omp parallel default(none) shared(var)
    {
        printf("Value of var: %d\n", var);
    }
}
