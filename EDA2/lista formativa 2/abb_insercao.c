#include <stdlib.h>
typedef struct no
{
    int valor;
    struct no *esq, *dir;
} no;

no *criarNo(int valor)
{
    no *aux = (no *)malloc(sizeof(no));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}

no *inserir(no *raiz, int v)
{
    if (raiz == NULL)
    {
        return criarNo(v);
    }

    if (v < raiz->valor)
    {
        raiz->esq = inserir(raiz->esq, v);
    }
    else if (v > raiz->valor)
    {
        raiz->dir = inserir(raiz->dir, v);
    }
    return raiz;
}