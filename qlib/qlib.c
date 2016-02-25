#include <stdio.h>
#include <stdlib.h>
#include "qlib.h"

//Cria lista
node *criar(int vlr)
{
    node *aux;
    aux = (node*) malloc(sizeof(node));
    if(aux != NULL)
    {
        aux->num = vlr;
        aux->next = NULL;
        return aux;
    }
    else
    {
        printf("ERRO EM MALLOC");
    }

    return NULL;
}

//Adiciona elementos a lista
void addNum(node **lista, int vlr)
{
    node *temp = *lista;
    node *novo = criar(vlr);

    if(temp == NULL)
    {
        *lista = novo;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = novo;
    }
}

void freeLista(node **lista)
{
    node *aux;
    node *temp = *lista;

    if(temp != NULL)
    {
        while(temp != NULL)
        {
            aux = temp;
            temp = temp->next;
            free(aux);
        }

    }
}

void printLista(node *temp)
{
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            printf("%d ", temp->num);
            temp = temp->next;
        }
    }
    else
    {
        printf("Lista vazia.");
    }
}
