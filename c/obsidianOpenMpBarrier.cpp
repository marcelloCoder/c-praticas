#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    //define loop iterator variable outside parallel region
    int i;
    int threadId;
	
    /*
	#pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();

        //create the loop to have each thread print hello.
        for(i = 0; i < omp_get_max_threads(); i++){
            printf("Hello from process: %d\n", thread_id);
        }
    }
   */
    
    /*
    #pragma omp parallel private(threadId)
    {
        threadId = omp_get_thread_num();

        for(i = 0; i < omp_get_max_threads(); i++){
            if(i == threadId){
                printf("Hello from process: %d\n", threadId);
            }
        }
    }
    */
    #pragma omp parallel private(threadId)
    {
        threadId = omp_get_thread_num();

        for( int i = 0; i < omp_get_max_threads(); i++){
            if(i == omp_get_thread_num()){
                printf("Hello from process: %d\n", threadId);
            }
            #pragma omp barrier
        }
    }
    return 0;
    
}
