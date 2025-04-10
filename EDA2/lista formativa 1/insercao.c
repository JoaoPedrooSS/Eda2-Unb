#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x);
void insere_antes(celula *le, int x, int y);

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));

    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y)
{
    celula *aux, *novo = malloc(sizeof(celula));
    aux = le;
    novo->dado = x;

    if (le->prox == NULL)
    {
        novo->prox = le->prox;
        le->prox = novo;
        return;
    }
    if (le->prox->dado == y)
    {
        novo->prox = le->prox;
        le->prox = novo;
        return;
    }

    while (aux->prox != NULL && aux->prox->dado != y)
    {
        aux = aux->prox;
    }
    if (aux->prox != NULL && aux->prox->dado == y)
    {
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    else
    {
        aux->prox = novo;
        novo->prox = NULL;
    }
}