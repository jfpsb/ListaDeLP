#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qlib.h"

int replace(char **string)
{
    int i = 0, espacos = 0;

    char *aux;

    aux = *string;

    while(aux[i] != '\0')
    {
        if(aux[i] == ' ')
        {
            espacos++;
            aux[i] = '-';
        }

        i++;
    }

    return espacos;
}

int main()
{
    char *frase;
    int quantEsp;

    frase = malloc(sizeof(char)*100);

    printf("Digite sua string: ");
    fgets(frase, 100, stdin);

    quantEsp = replace(&frase);

    printf("\nQuantidade de espacos: %d\nFrase modificada: %s", quantEsp, frase);

    return 0;
}
