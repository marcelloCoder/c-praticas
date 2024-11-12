#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *x;

    x = malloc(sizeof(int));

    if (x != NULL)
    {
        printf("MEMORIA ALOCADA\n");
        printf("x = %d\n", *x);
        *x = 50;
        printf("x = %d\n", *x);
    }else{
        printf("ERRO AO ALOCAR MEMORIA\n");
    }
    
    return 0;
}
