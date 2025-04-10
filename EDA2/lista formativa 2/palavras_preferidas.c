#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula
{
    int num;
    char palavra[17];
    struct celula *prox;
} celula;

typedef struct
{
    celula *tb;
    int M;
    int N;
} TH;

void THinicializa(TH *h, int M);
int THverifica(TH *h, char *palavra);
int THinsere(TH *h, char *palavra);
void THbusca(TH *h, char *palavra);
void THlibera(TH *h);
void THimprime(TH *h);
int hash(const char *palavra, int M);

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

int hash(const char *palavra, int M)
{
    unsigned int soma = 0;
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        soma = (soma * 31 + palavra[i]) % M;
    }
    return soma % M;
}

int THinsere(TH *h, char *palavra)
{
    if (THverifica(h, palavra))
    {
        celula *temp = h->tb[hash(palavra, h->M)].prox;
        while (temp && strcmp(temp->palavra, palavra) != 0)
        {
            temp = temp->prox;
        }
        temp->num++;
        return 0;
    }
    int i = hash(palavra, h->M);
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->num = 1;
    strncpy(nova->palavra, palavra, 16);
    nova->palavra[16] = '\0';
    nova->prox = h->tb[i].prox;
    h->tb[i].prox = nova;
    h->N++;
    return 1;
}

int THverifica(TH *h, char *palavra)
{
    int i = hash(palavra, h->M);
    celula *temp = h->tb[i].prox;
    while (temp != NULL)
    {
        if (strcmp(palavra, temp->palavra) == 0)
        {
            return 1;
        }
        temp = temp->prox;
    }
    return 0;
}

void THbusca(TH *h, char *palavra)
{
    int i = hash(palavra, h->M);
    celula *temp = h->tb[i].prox;
    while (temp != NULL)
    {
        if (strcmp(palavra, temp->palavra) == 0)
        {
            printf("%d\n", temp->num);
            return;
        }
        temp = temp->prox;
    }
    printf("0\n");
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

void THzera(TH *h, char *palavra)
{
    int i = hash(palavra, h->M);
    celula *temp = h->tb[i].prox;
    while (temp != NULL)
    {
        if (strcmp(palavra, temp->palavra) == 0)
        {
            temp->num = 0;
            return;
        }
        temp = temp->prox;
    }
}

void THimprime(TH *h)
{
    for (int i = 0; i < h->M; i++)
    {
        celula *temp = h->tb[i].prox;
        while (temp != NULL)
        {
            printf("%d %s\n", temp->num, temp->palavra);
            temp = temp->prox;
        }
    }
}

int main()
{
    TH tabela;
    THinicializa(&tabela, 65536);

    int num;
    char palavra[17];

    while (scanf("%d %s", &num, palavra) != EOF)
    {
        switch (num)
        {
        case 1:
            THinsere(&tabela, palavra);
            break;
        case 2:
            THbusca(&tabela, palavra);
            break;
        case 3:
            THzera(&tabela, palavra);
        }
    }

    THlibera(&tabela);
    return 0;
}
