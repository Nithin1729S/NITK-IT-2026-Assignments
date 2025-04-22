#include <omp.h>
#include <stdio.h>

int main() {
    int array[]={100,12,34,56,78,9,3,-12};
    int min_val = 1e9;  
    
    #pragma omp parallel for reduction(min:min_val)
    for (int i = 0; i < 8; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }

    printf("Min value = %d\n", min_val);
    return 0;
}
