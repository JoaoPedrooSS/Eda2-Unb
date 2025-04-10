
#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

typedef struct
{
    celula *tb;
    int M;
    int N;
} TH;

int hash(int chave, int M)
{
    return chave % M;
}

void THinsere(TH *h, int ch)
{
    if (THbusca(h, ch))
    {
        return;
    }
    int i = hash(ch, h->M);
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[i].prox;
    h->tb[i].prox = nova;
    h->N++;
}

int THremove(TH *h, int ch)
{
    int i = hash(ch, h->M);
    celula *temp = &h->tb[i];
    while (temp->prox != NULL)
    {
        if (temp->prox->dado == ch)
        {
            celula *remove = temp->prox;
            temp->prox = remove->prox;
            free(remove);
            h->N--;
            return 0;
        }
        temp = temp->prox;
    }
    return -1;
}

int THbusca(TH *h, int ch)
{
    int i = hash(ch, h->M);
    celula *temp = h->tb[i].prox;
    while (temp != NULL)
    {
        if (temp->dado == ch)
        {
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}
