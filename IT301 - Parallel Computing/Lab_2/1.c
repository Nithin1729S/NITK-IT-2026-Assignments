#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
    
    struct timeval TimeValue_Start;
    struct timeval TimeValue_Final;
    long time_start, time_end;
    double time_overhead;

    
    long long num_steps = 1000000000;
    double step = 1.0 / (double)num_steps;
    double pi;

    
    int thread_counts[] = {1, 2, 4, 8,16,32};
    int num_cases = sizeof(thread_counts) / sizeof(thread_counts[0]);

    for (int t = 0; t < num_cases; t++) {
        int num_threads = thread_counts[t];
        omp_set_num_threads(num_threads);  

        double sum = 0.0;

        gettimeofday(&TimeValue_Start, NULL);

        #pragma omp parallel
        {
            double local_sum = 0.0;
            #pragma omp for
            for (long long i = 0; i < num_steps; i++) {
                double x = (i + 0.5) * step;
                local_sum += 4.0 / (1.0 + x * x);
            }
            #pragma omp atomic
            sum += local_sum;
        }

        
        gettimeofday(&TimeValue_Final, NULL);

        pi = step * sum;
        printf("Calculated Pi value with %d threads: %lf\n", num_threads, pi);

        
        time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
        time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
        time_overhead = (time_end - time_start) / 1000000.0;
        
        printf("Time in Seconds (T) with %d threads: %lf\n\n", num_threads, time_overhead);
    }

    return 0;
}
