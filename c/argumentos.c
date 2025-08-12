#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    printf("argc: %d\n", argc);

    if (argc > 1)
    {
        printf("argv[0]: %s\n",argv[0]);	
		printf("argv[1]: %s\n",argv[1]);
    }
    
    return 0;
}
