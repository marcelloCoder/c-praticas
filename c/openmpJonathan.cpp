#include <stdio.h>
#include <omp.h>
#include <math.h>	

#define PI 3.14

int main(){
	
	int x;
	
	#pragma omp parallel private(x)
	{
		x = omp_get_thread_num();
		
		#pragma omp master
		{
			printf("num threads: %d\n", x);
		}
	}
}
