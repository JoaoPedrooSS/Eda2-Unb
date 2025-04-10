#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *minimo(no *r)
{
    if (r->esq == NULL)
    {
        return r;
    }
    r = r->esq;
    while (r->esq != NULL)
    {
        r = r->esq;
    }
    return r;
}
