#include <stdio.h>
#include <stdlib.h>
#include "qlib.h"

//Retorna o node anterior passado como parametro
node *getNodeAnt(node *lista, node *ant)
{
    node *tmp = lista;

    if(tmp != NULL)
    {
        while(tmp->next != NULL)
        {
            if(tmp->next == ant)
            {
                return tmp;
            }
            tmp = tmp->next;
        }
    }

    return NULL;
}

void removerVizinhos(node **lista, int vlr)
{
    node *temp  = *lista;
    node *aux = NULL;
    node *ant = NULL;
    node *prox = NULL;
    node *antant = NULL;

    if(*lista != NULL)
    {
        if(temp->num == vlr && temp->next != NULL)
        {
            aux = temp->next;
            temp->next = aux->next;
            free(aux);
        }
        else
        {
            ant = temp;

            while(ant->next != NULL)
            {
                if(ant->next->num == vlr && ant->next != NULL)
                {
                    aux = ant->next;
                    prox = ant->next->next;
                    break;
                }

                ant = ant->next;
            }

            //Recupera o node anterior ao anterior
            antant = getNodeAnt(*lista, ant);

            if(antant == NULL)
            {
                *lista = ant->next;
                temp = *lista;
                temp->next = prox->next;
            }
            else
            {
                if(antant->next != NULL)
                    antant->next = aux;
                if(aux->next != NULL && prox != NULL)
                    aux->next = prox->next;
            }

            if(ant != NULL)
                free(ant);
            if(prox != NULL)
                free(prox);
        }
    }
}

int main()
{
    int i, escolhido, repetir;
    node *lista;

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

    printf("\nDe qual vc vai remover os vizinhos? ");
    scanf("%d", &escolhido);

    removerVizinhos(&lista, escolhido);

    printf("\nSua nova lista: \n");

    printLista(lista);

    printf("\n\nDeseja repetir? Aperte 1 - SIM, qualquer outro - NAO: ");
    scanf("%d", &repetir);

    printf("\n");

    freeLista(&lista);

    }while(repetir == 1);

    printf("Acabou-se.\n");

    return 0;
}
