#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilhaNo
{
    no *dado;
    struct pilhaNo *prox;
} Pilha_No;

Pilha_No *createStack()
{
    return NULL;
}

int pilha(Pilha_No *topo)
{
    return topo == NULL;
}

no *peek(Pilha_No *topo)
{
    if (pilha(topo))
    {
        return NULL;
    }
    return topo->dado;
}

void empilha(Pilha_No **topo, no *elemento)
{
    Pilha_No *temp = (Pilha_No *)malloc(sizeof(Pilha_No));
    temp->dado = elemento;
    temp->prox = *topo;
    *topo = temp;
}

no *desempilha(Pilha_No **topo)
{
    if (pilha(*topo))
    {
        return NULL;
    }
    Pilha_No *temp = *topo;
    no *dado = temp->dado;
    *topo = temp->prox;
    free(temp);
    return dado;
}

void pos_ordem(no *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    Pilha_No *p = createStack();

    no *ultimo = NULL;

    while (!pilha(p) || raiz != NULL)
    {
        if (raiz != NULL)
        {
            empilha(&p, raiz);
            raiz = raiz->esq;
        }
        else
        {
            no *topo = peek(p);
            if (topo->dir != NULL && ultimo != topo->dir)
            {
                raiz = topo->dir;
            }
            else
            {
                printf("%d ", topo->dado);
                ultimo = desempilha(&p);
            }
        }
    }
}
