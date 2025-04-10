#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *remover(no *raiz, int v)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (v < raiz->chave)
    {
        raiz->esq = remover(raiz->esq, v);
    }
    else if (v > raiz->chave)
    {
        raiz->dir = remover(raiz->dir, v);
    }
    else
    {
        if (raiz->esq == NULL)
        {
            no *aux = raiz->dir;
            free(raiz);
            return aux;
        }
        if (raiz->dir == NULL)
        {
            no *aux = raiz->esq;
            free(raiz);
            return aux;
        }

        no *aux = raiz->esq;
        while (aux->dir != NULL)
        {
            aux = aux->dir;
        }
        raiz->chave = aux->chave;
        raiz->esq = remover(raiz->esq, aux->chave);
    }

    return raiz;
}