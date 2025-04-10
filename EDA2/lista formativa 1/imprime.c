#include <stdio.h>
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le);
void imprime_rec(celula *le);

void imprime(celula *le)
{
    celula *atual = le->prox;
    while (atual)
    {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    puts("NULL");
}

void imprime_rec(celula *le)
{
    if (le->prox != NULL)
    {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
    else
        puts("NULL");
}