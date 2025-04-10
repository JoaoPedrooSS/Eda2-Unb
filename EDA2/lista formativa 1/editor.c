#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No
{
    char frase[101];
    struct No *prox;
} No;

No *empilha(No *topo, char frase[])
{
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->frase, frase);
    novo->prox = topo;
    return novo;
}

No *desempilha(No *topo, char saida[])
{
    if (topo == NULL)
    {
        strcpy(saida, "NULL");
        return NULL;
    }
    strcpy(saida, topo->frase);
    No *aux = topo;
    topo = topo->prox;
    free(aux);
    return topo;
}

int main()
{
    No *topo = NULL;
    char comando[10], frase[101];

    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "inserir") == 0)
        {

            scanf(" %[^\n]", frase);
            topo = empilha(topo, frase);
        }
        else if (strcmp(comando, "desfazer") == 0)
        {
            char saida[101];
            topo = desempilha(topo, saida);
            printf("%s\n", saida);
        }
    }

    while (topo != NULL)
    {
        char saida[101];
        topo = desempilha(topo, saida);
    }

    return 0;
}