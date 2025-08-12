#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
	int i, sum = 0, sum2 = 0; //shared
	int thread_sum[4];
	int thread2_sum[3];
	omp_set_num_threads(4);
    #pragma omp parallel
    {
    	int ID = omp_get_thread_num(); // private
    	thread_sum[ID] = 0;;
    	#pragma omp for
		for(i = 1; i <= 100; i++){
			thread_sum[ID] += ID;
		} 
		
		for(i=0; i<4; i++){
			sum += thread_sum[i];
		}
		
        printf("SUM: %d\n", sum);
    }
    
    #pragma omp parallel
    {
    	int ID2 = omp_get_thread_num();
    	thread2_sum[ID2] = 0;
    	#pragma omp for
		for(i = 1; i <= 100; i++){
			thread2_sum[ID2] += ID2;
		} 

		
		for(i=0; i<3; i++){
			sum2 += thread2_sum[i];
		}
        printf("--SUM2: %d\n", sum2);
    }
    return 0;
}
