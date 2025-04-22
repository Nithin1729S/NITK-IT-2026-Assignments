#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
    
    struct timeval TimeValue_Start;
    struct timeval TimeValue_Final;
    long time_start, time_end;
    double sequential_time, parallel_time, speedup, efficiency;
    int num_threads = omp_get_max_threads();  

    
    long long num_steps = 1000000000;  //iters
    double step = 1.0 / (double)num_steps;
    double sum = 0.0;

    // sequential
    gettimeofday(&TimeValue_Start, NULL);
    for (long long i = 0; i < num_steps; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    gettimeofday(&TimeValue_Final, NULL);

    // sequential time
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    sequential_time = (time_end - time_start) / 1000000.0;

    printf("Sequential Time in Seconds (T_seq): %lf\n", sequential_time);


    sum = 0.0; //reset

   //parallel
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

    //parallel
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    parallel_time = (time_end - time_start) / 1000000.0;

   
    printf("Parallel Time in Seconds (T_par): %lf\n", parallel_time);

   
    speedup = sequential_time / parallel_time;
    efficiency = speedup / num_threads;

   
    printf("Speedup: %lf\n", speedup);
    printf("Efficiency: %lf\n", efficiency);

    return 0;
}
