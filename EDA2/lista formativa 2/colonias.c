#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula
{
    int num_colonia;
    char alimento[11];
    struct celula *prox;
} celula;

typedef struct
{
    celula *tb;
    int M;
    int N;
} TH;

void THinicializa(TH *h, int M);
int THbusca(TH *h, int num_colonia, char *alimento);
int THinsere(TH *h, int num_colonia, char *alimento);
void THimprime(TH *h)
{
    for (int i = 0; i < h->M; i++)
    {
        celula *temp = h->tb[i].prox;
        while (temp != NULL)
        {
            printf("%d %s\n", temp->num_colonia, temp->alimento);
            temp = temp->prox;
        }
    }
}

int hash(int num_colonia, int M)
{
    return num_colonia % M;
}

void THinicializa(TH *h, int M)
{
    h->M = M;
    h->N = 0;
    h->tb = (celula *)malloc(M * sizeof(celula));
    for (int i = 0; i < M; i++)
    {
        h->tb[i].prox = NULL;
    }
}

int THinsere(TH *h, int num_colonia, char *alimento)
{
    if (THbusca(h, num_colonia, alimento))
    {
        return 0;
    }
    int i = hash(num_colonia, h->M);
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->num_colonia = num_colonia;
    strncpy(nova->alimento, alimento, 10);
    nova->alimento[10] = '\0';
    nova->prox = h->tb[i].prox;
    h->tb[i].prox = nova;
    h->N++;
    return 1;
}

int THbusca(TH *h, int num_colonia, char *alimento)
{
    int i = hash(num_colonia, h->M);
    celula *temp = h->tb[i].prox;
    while (temp != NULL)
    {
        if(strcmp(alimento, temp->alimento) == 0 && temp->num_colonia == num_colonia)
        {
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}

void THlibera(TH *h)
{
    for (int i = 0; i < h->M; i++)
    {
        celula *temp = h->tb[i].prox;
        while (temp != NULL)
        {
            celula *remove = temp;
            temp = temp->prox;
            free(remove);
        }
    }
    free(h->tb);
}

int main()
{
    TH tabela;
    THinicializa(&tabela, 1048576);

    int col;
    char alim[11];

    while (scanf("%d %s", &col, alim) != EOF)
    {
        if (!THinsere(&tabela, col, alim))
            printf("%d\n", col);
    }
}