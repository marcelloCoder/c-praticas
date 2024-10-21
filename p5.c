// P5) Forneça um exemplo de aplicação real que envolva o problema de ordenação.
// Um exemplo real de aplicação que envolve o problema de ordenação em C é a
// organização de registros de clientes em um sistema bancário.

#include <stdio.h>

#define TAM 3

struct Cliente
{
    char nome[255];
    int numeroConta;
    float saldo;
};

void ordenar(struct Cliente clientes[], int n)
{
    int i, j, index;
    struct Cliente temp;

    for (i = 0; i < n - 1; i++)
    {
        if (clientes[j].saldo < clientes[index].saldo)
        {
            index = j;
        }
        temp = clientes[i];
        clientes[i] = clientes[index];
        clientes[index] = temp;
    }
}

int main(int argc, char const *argv[])
{

    struct Cliente clientes[TAM] = {
        {"Ana", 1001, 5000.75},
        {"Carlos", 1002, 3000.50},
        {"Beatriz", 1003, 4000.25}};

    ordenar(clientes, TAM);

    printf("Clientes ordenados por saldo:\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("\nNome: %s, Conta: %d, Saldo: %.2f\n", clientes[i].nome, clientes[i].numeroConta, clientes[i].saldo);
    }

    return 0;
}
