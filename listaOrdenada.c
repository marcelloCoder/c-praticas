//P1) Quais problemas que possuem, geralmente, complexidade da ordem de log n?
//Um exemplo de algoritmo com complexidade O(log n) é uma busca binária em uma lista já ordenada.

//P2) Quais problemas que costumam ser exponenciais?
//Comum na solução de problemas quando se usa força bruta para resolvê-los.
// Algoritmo com complexidade exponencial, não é executável para valores de N muito grandes.
// Algoritmos desta ordem de complexidade geralmente não são úteis sob o ponto de vista prático.
// Por exemplo, quando n é vinte, o tempo de execução é cerca de um milhão.
// Problemas que somente podem ser resolvidos através de algoritmos exponenciais são ditos intratáveis.

//P3) Escreva um algoritmo que receba valores em um vetor de 10 posições e imprima
//“ORDENADO” se o vetor estiver em ordem crescente. Qual é a função de custo de pior caso e sua
//ordem de complexidade O?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 10

void ordenado(int vetor[]){
    int i, j ,a;
    for (i = 0; i < MAXTAM; ++i){
    for (j = i + 1; j < MAXTAM; ++j)
    {
        if (vetor[i] > vetor[j])
        {
            a =  vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = a;
            printf("\nORDENADO");
        }
    }
}
}

int main(int argc, char const *argv[])
{
    int vetor[MAXTAM] = {6,1,2,3,4,5,6,7,8,9};
    ordenado(vetor);
    for (int i = 0; i < MAXTAM; i++)
    {
        printf("%d", vetor[i]);
    }
    
    
    return 0;
}

/*Função de custo de pior caso: O pior caso acontece quando o vetor não está ordenado, e a comparação precisa ser
 feita até encontrar o primeiro par de elementos fora de ordem ou até o final do vetor, se ele for ordenado.
Ordem de complexidade O: A função percorre o vetor uma única vez, fazendo comparações consecutivas entre elementos 
adjacentes. Portanto, a complexidade do algoritmo é O(n), onde n é o tamanho do vetor, que neste caso é 10.*/
