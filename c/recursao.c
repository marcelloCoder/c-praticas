#include <stdio.h>

void imprimir(int n){
    if (n == 0)
    {
        printf("%d ", n);
    }else{
        // printf("%d ,", n);
        imprimir(n - 1);
        printf("%d ", n);
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("DIGITE VALOR MAIOR QUE ZERO : ");
    scanf("%d", &n);

    imprimir(n);

    return 0;
}
