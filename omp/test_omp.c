#include <omp.h>
#include <stdio.h>

int main() {
   int num_threads = omp_get_max_threads(); 

   printf("Maximum number of OpenMP threads: %d\n", num_threads);

#pragma omp parallel 
   printf("thread %d / %d\n", omp_get_thread_num(), num_threads);
}
