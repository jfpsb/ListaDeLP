#include <stdio.h>
#include <stdlib.h>
#include "qlib.h"

node *uniaoAB(node *A, node *B)
{
    node *uniao = NULL;
    node *aux = A;
    int repetido = 0;

    //Copia os elementos nao repetidos de B em A na Uniao
    if(A != NULL && B != NULL)
    {
        //Copia os elementos de A para uniao
        while(aux != NULL)
        {
            addNum(&uniao, aux->num);
            aux = aux->next;
        }

        while (B != NULL)
        {
            repetido = 0;

            aux = A;

            while(aux != NULL)
            {
                if(B->num == aux->num)
                {
                    repetido = 1;
                    break;
                }

                aux = aux->next;
            }

            if(repetido == 0)
                addNum(&uniao, B->num);

            B = B->next;
        }
    }
    else
    {
        printf("\nUm dos conjuntos ou os dois sao invalidos.");
    }

    return uniao;
}

int jaExiste(node *intersecao, node *valor)
{
    node *aux = intersecao;

    if(aux != NULL)
    {
        while(aux != NULL)
        {
            if(valor->num == aux->num)
            {
                return 1;
            }

            aux = aux->next;
        }
    }

    return 0;
}

node *intersecaoAB(node *A, node *B)
{
    node *intersecao = NULL;
    node *auxA = A;
    node *auxB = B;

    if(auxA != NULL && auxB != NULL)
    {
        while(auxA != NULL)
        {
            auxB = B;

            while(auxB != NULL)
            {
                if(auxA->num == auxB->num)
                {
                    addNum(&intersecao, auxB->num);
                }
                auxB = auxB->next;
            }
            auxA = auxA->next;
        }
    }

    return intersecao;
}

node *diferencaAB(node *L1, node *L2)
{
    node *diferenca = NULL;
    node *minuendo = L1;
    node *subtraendo = L2;
    int existe = 0;

    if(minuendo != NULL && subtraendo != NULL)
    {
        while(minuendo != NULL)
        {
            subtraendo = L2;
            existe = 0;

            while(subtraendo != NULL)
            {
                if(minuendo->num == subtraendo->num)
                {
                    existe = 1;
                    break;
                }

                subtraendo = subtraendo->next;
            }

            if(existe != 1)
            {
                addNum(&diferenca, minuendo->num);
            }

            minuendo = minuendo->next;
        }
    }

    return diferenca;
}

int main()
{
    int i, repetir, escolhido;
    node *uniao, *diferenca, *intersecao, *A, *B;

    do
    {
        uniao = NULL;
        diferenca = NULL;
        intersecao = NULL;
        A = NULL;
        B = NULL;

        printf("Ha' 10 numeros na lista A.\n");

        for(i = 0; i < 10; i++)
        {
            addNum(&A, i + 1);
        }

        printf("Ha' 10 numeros na lista B.\n");

        for(i = 4; i < 14; i++)
        {
            addNum(&B, i + 1);
        }

        printf("Lista A: \n");
        printLista(A);

        printf("\nLista B: \n");
        printLista(B);

        printf("\n\n1 - Uniao de A e B\n");
        printf("2 - Intersecao de A e B\n");
        printf("3 - Diferenca de A e B\n");
        printf("Escolha qual operacao deseja: ");

        scanf("%d", &escolhido);

        switch(escolhido)
        {
        case 1:
            uniao = uniaoAB(A, B);
            printf("\nUNIAO entre A e B: ");
            printLista(uniao);
            break;
        case 2:
            intersecao = intersecaoAB(A, B);
            printf("\nINTERSECAO entre A e B: ");
            printLista(intersecao);
            break;
        case 3:
            diferenca = diferencaAB(A, B);
            printf("\nDIFERENCA entre A e B: ");
            printLista(diferenca);
            diferenca = diferencaAB(B, A);
            printf("\nDIFERENCA entre B e A: ");
            printLista(diferenca);
            break;
        }

        printf("\n\nDeseja repetir? Aperte 1 - SIM, qualquer outro - NAO: ");
        scanf("%d", &repetir);

        printf("\n");

        freeLista(&A);
        freeLista(&B);
        freeLista(&uniao);
        freeLista(&intersecao);
        freeLista(&diferenca);
    }
    while(repetir == 1);

    printf("Acabou-se.\n");

    return 0;
}
