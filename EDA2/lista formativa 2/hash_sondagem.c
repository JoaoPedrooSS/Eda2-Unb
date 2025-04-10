#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int valor;
} celula;

typedef struct
{
    celula *tb;
    int M;
    int N;
} TH;

int aumentaTamanho(int M);

int hash(int ch, int M)
{
    return ch % M;
}

void THinicializa(TH *h, int M)
{
    h->M = M;
    h->N = 0;
    h->tb = (celula *)malloc(M * sizeof(celula));
    for (int i = 0; i < M; i++)
    {
        h->tb[i].valor = -1;
    }
}

void THredimensiona(TH *h)
{
    int novo_tamanho = aumentaTamanho(h->M);
    celula *nova_tabela = (celula *)malloc(novo_tamanho * sizeof(celula));

    for (int i = 0; i < novo_tamanho; i++)
    {
        nova_tabela[i].valor = -1;
    }

    for (int i = 0; i < h->M; i++)
    {
        if (h->tb[i].valor != -1)
        {
            int nova_posicao = hash(h->tb[i].valor, novo_tamanho);
            while (nova_tabela[nova_posicao].valor != -1)
            {
                nova_posicao = (nova_posicao + 1) % novo_tamanho;
            }
            nova_tabela[nova_posicao].valor = h->tb[i].valor;
        }
    }

    free(h->tb);
    h->tb = nova_tabela;
    h->M = novo_tamanho;
}

void THinsere(TH *h, int ch)
{
    if (THbusca(h, ch))
    {
        return;
    }

    if (h->N > h->M / 2)
    {
        THredimensiona(h);
    }

    int posicao = hash(ch, h->M);
    while (h->tb[posicao].valor != -1)
    {
        posicao = (posicao + 1) % h->M;
    }
    h->tb[posicao].valor = ch;
    h->N++;
}

int THremove(TH *h, int ch)
{
    int posicao = hash(ch, h->M);
    while (h->tb[posicao].valor != -1)
    {
        if (h->tb[posicao].valor == ch)
        {
            h->tb[posicao].valor = -1;
            h->N--;

            int nova_posicao = (posicao + 1) % h->M;
            while (h->tb[nova_posicao].valor != -1)
            {
                int chaveReinserir = h->tb[nova_posicao].valor;
                h->tb[nova_posicao].valor = -1;
                h->N--;

                THinsere(h, chaveReinserir);
                nova_posicao = (nova_posicao + 1) % h->M;
            }

            return 0;
        }
        posicao = (posicao + 1) % h->M;
    }
    return -1;
}

int THbusca(TH *h, int ch)
{
    int posicao = hash(ch, h->M);
    while (h->tb[posicao].valor != -1)
    {
        if (h->tb[posicao].valor == ch)
        {
            return 1;
        }
        posicao = (posicao + 1) % h->M;
    }
    return 0;
}
