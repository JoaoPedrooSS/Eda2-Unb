#include <stdlib.h>
typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;


no *maximo(no *raiz)
{
    if (raiz->dir == NULL)
    {
        return raiz;
    }
    raiz = raiz->dir;
    while (raiz->dir != NULL)
    {
        raiz = raiz->dir;
    }
    return raiz;
}
