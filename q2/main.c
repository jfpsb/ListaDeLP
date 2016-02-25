#include <stdio.h>
#include <stdlib.h>
#include "qlib.h"

node* buscaElemento(node *lista, int vlr)
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

int main()
{
    int i, repetir, escolhido;
    node *lista, *buscado;

    do
    {
        lista = NULL;

        printf("Ha' 15 numeros na lista.\n");

        for(i = 0; i < 15; i++)
        {
            addNum(&lista, i + 1);
        }

        printf("Sua lista: \n");
        printLista(lista);

        printf("\nQue elemento vc quer buscar? ");
        scanf("%d", &escolhido);

        buscado = buscaElemento(lista, escolhido);

        if(buscado != NULL)
        {
            printf("\nElemento %d encontrado.", buscado->num);
        }
        else
        {
            printf("\nElemento nao encontrado.");
        }

        printf("\n\nDeseja repetir? Aperte 1 - SIM, qualquer outro - NAO: ");
        scanf("%d", &repetir);

        printf("\n");

        freeLista(&lista);
    }
    while(repetir == 1);

    printf("Acabou-se.\n");

    return 0;
}
