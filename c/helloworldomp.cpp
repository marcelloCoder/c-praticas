#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
	int id;
	omp_set_num_threads(4);
    #pragma omp parallel
    {
    	id = omp_get_thread_num();
        printf("Hello from process: %d\n", omp_get_thread_num());
    }
    return 0;
}
