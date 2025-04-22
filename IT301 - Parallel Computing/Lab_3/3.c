#include <omp.h>
#include <stdio.h>

int main()
{
    int n = 10;
    int arr[] = {1, 2, 3, 4, 5};

#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp critical
            {
                for (int i = 0; i < 5; i++)
                {
                    arr[i] *= 2;
                }
                printf("\nThe first section was executed by thread no %d", omp_get_thread_num());
            }
        }

#pragma omp sections
        {
#pragma omp section
            {
#pragma omp critical
                {
                    for (int i = 0; i < 5; i++)
                    {
                        arr[i] += 2;
                    }
                    printf("\nThe second section was executed by thread no %d", omp_get_thread_num());
                }
            }
        }
    }

    printf("\nFinally the array looks like this: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
