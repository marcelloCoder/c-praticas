#include <stdio.h>

#define MAXTAM 31

void inicializaTabela(int tabela[])
{
    for (int i = 0; i < MAXTAM; i++)
    {
        tabela[i] = 0;
    }
}

int funcaoHash(int chave)
{
    return chave % MAXTAM;
}

void inserir(int tabela[], int valor)
{
    int id = funcaoHash(valor);
    while (tabela[id] != 0)
    {
        id = funcaoHash(id + 1);
    }
    tabela[id] = valor;
}

int busca(int tabela[], int chave)
{
    int id = funcaoHash(chave);
    printf("\n\t Indice gerado: %d\n", id);
    while (tabela[id] != 0)
    {
        if (tabela[id] == chave)
        {
            return tabela[id];
        }
        else
        {
            id = funcaoHash(id + 1);
        }
    }
    return 0;
}

void imprimir(int tabela[])
{
    int i;
    for (i = 0; i < MAXTAM; i++)
    {
        printf("%d = %d\n", i, tabela[i]);
    }
}

int main(int argc, char const *argv[])
{
    int opcao, valor, retorno, tabela[MAXTAM];

    inicializaTabela(tabela);

    do
    {
        printf("\n\t 0 - Sair\n\t 1 - Inserir\n\t 2 - Buscar \n\t 3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tQual Valor deseja inserir?");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tQual Valor deseja buscar?");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if (retorno != 0)
            {
                printf("\tValor encontrado: %d\n", retorno);
            }
            else
            {
                printf("\tValor nao encontrado!\n");
            }
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!");
        }
    } while (opcao != 0);

    return 0;
}
