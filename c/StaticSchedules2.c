#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#define THREADS 4
#define N 16

double divisao(double x, double y){
	double result = x / y;
	return result;
}

int main ( ) {
	int i;
	#pragma omp parallel for schedule(static) num_threads(THREADS)
	for (i = 0; i < N; i++) {
	/* wait for i seconds */
		sleep(i);
		printf("Thread %d has completed iteration %d.\n", omp_get_thread_num( ), i);
		printf("Divisao method %.2f\n", divisao(i,N));
		printf("\n");
	}
	/* all threads done */
	printf("All done!\n");
	return 0;
}
