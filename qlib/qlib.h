#ifndef QLIB_H_INCLUDED
#define QLIB_H_INCLUDED

typedef struct _node
{
    int num;
    struct _node *next;
}node;

node *criar(int vlr);
void addNum(node **lista, int vlr);
void freeLista(node **lista);
void printLista(node *temp);

#endif // QLIB_H_INCLUDED
