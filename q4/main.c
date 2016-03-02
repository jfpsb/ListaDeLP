#include <stdio.h>
#include <stdlib.h>
#include "qlib.h"

typedef struct _hash
{
    node *cab;
}hash;

node *buscaElemento(node *lista, int vlr)
{
    node *temp = lista;

    if(temp != NULL)
    {
        if(temp->num == vlr)
        {
            return temp;
        }
        else
        {
            if(temp->next != NULL)
                buscaElemento(temp->next, vlr);
        }
    }
}

int hashing(int vlr, int m)
{
    return vlr%m;
}

int main()
{
    int opcao, m, vlr, i, repetir = 0;
    hash *tab;
    node *busca;

    printf("Digite o tamanho de sua tabela: ");
    scanf("%d", &m);

    tab = malloc(m*sizeof(hash));

    for(i = 0; i < m; i++)
    {
        tab[i].cab = NULL;
    }

    if(tab == NULL) exit(1);

    do
    {
        printf("1 - Adicionar\n");
        printf("2 - Consultar\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        printf("Digite o valor: ");
        scanf("%d", &vlr);

        switch(opcao)
        {
        case 1:
            addNum(&tab[hashing(vlr, m)].cab, vlr);
            break;
        case 2:
            busca = buscaElemento(tab[hashing(vlr, m)].cab, vlr);
            if(busca != NULL)
                printf("\nAchou");
            else
                printf("\nNao Achou");
            break;
        }

        printf("\nRepetir? 1 - NAO, QUALQUER OUTRO - SIM: ");
        scanf("%d", &repetir);

    }
    while(repetir != 1);

    for(i = 0; i < m; i++)
    {
        if(&tab[i].cab != NULL)
            freeLista(&tab[i].cab);
    }

    free(tab);

    printf("\nAcabou-se.\n");

    return 0;
}
