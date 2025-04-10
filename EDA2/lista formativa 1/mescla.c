#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3);

void mescla_listas(celula *l1, celula *l2, celula *l3)
{

    celula *atual = l3;

    while (l1->prox != NULL && l2->prox != NULL)
    {
        celula *novo = (celula *)malloc(sizeof(celula));

        if (l1->prox->dado < l2->prox->dado)
        {
            novo->dado = l1->prox->dado;
            l1 = l1->prox;
        }
        else
        {
            novo->dado = l2->prox->dado;
            l2 = l2->prox;
        }

        atual->prox = novo;
        atual = atual->prox;
    }

    while (l1->prox != NULL)
    {
        celula *novo = (celula *)malloc(sizeof(celula));
        novo->dado = l1->prox->dado;
        atual->prox = novo;
        atual = atual->prox;
        l1 = l1->prox;
    }

    while (l2->prox != NULL)
    {
        celula *novo = (celula *)malloc(sizeof(celula));
        novo->dado = l2->prox->dado;
        atual->prox = novo;
        atual = atual->prox;
        l2 = l2->prox;
    }

    atual->prox = NULL;
}
