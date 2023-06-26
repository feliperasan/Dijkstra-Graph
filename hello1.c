// OpenMP program to print Hello World
// using C language

// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    //printf("Max Available Procs = %d\n", omp_get_num_procs());
    printf("Max Available Threads = %d\n", omp_get_max_threads());
    // Beginning of parallel region
    #pragma omp parallel
    {
        printf("Hello World... from thread = %d \n", omp_get_thread_num());
    }
    // Ending of parallel region
}