#include <stdio.h>
#include <stdlib.h>
#include"omp.h"


int main(int argc, char **argv) 
{
    #pragma omp parallel
    {
        printf("Hello World from thread %d\n", omp_get_thread_num());
    }
}   