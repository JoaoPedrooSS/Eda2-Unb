#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p);
void remove_elemento(celula *le, int x);
void remove_todos_elementos(celula *le, int x);

int remove_depois(celula *p)
{
    celula *aux = malloc(sizeof(celula));

    if (p->prox != NULL)
    {
        aux = p->prox;
        p->prox = NULL;
        p->prox = aux->prox;
        return 1;
    }
    else
    {
        return 0;
    }
}

void remove_elemento(celula *le, int x)
{

    celula *aux = malloc(sizeof(celula));

    while (le->prox->dado != x && le->prox != NULL)
    {
        le = le->prox;
    }
    if (le->prox->dado == x && le->prox->dado != NULL)
    {
        aux = le->prox;
        le->prox = aux->prox;
    }
}

void remove_todos_elementos(celula *le, int x)
{

    celula *aux = malloc(sizeof(celula));

    while (le->prox != NULL)
    {
        if (le->prox->dado == x)
        {
            aux = le->prox;
            le->prox = aux->prox;
        }else{
            le = le->prox;
        }
    }
}