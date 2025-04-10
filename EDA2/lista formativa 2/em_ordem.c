#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct
{
    no *raiz;
} raiz;

void em_ordem(no *raiz)
{
    no *no_atual = raiz;
    if (raiz == NULL)
        return;

    int top = -1;
    no *pilha_de_nos[100];

    top++;
    pilha_de_nos[top] = raiz;

    while (top >= 0)
    {
        while(no_atual->esq != NULL)
        {
            top++;
            pilha_de_nos[top] = no_atual->esq;
            no_atual = no_atual->esq;
        }

        no_atual = pilha_de_nos[top];
        top--;
        printf("%d ", no_atual->dado);

        if(no_atual->dir != NULL){
        no_atual = no_atual->dir;
        }
    }
}

no *newNode(int dado)
{
    no *no_criado = (no *)malloc(sizeof(no));
    no_criado->dado = dado;
    no_criado->dir = NULL;
    no_criado->esq = NULL;
    return no_criado;
}

int main()
{
    // Exemplo de árvore binária
    no *raiz = newNode(2);
    raiz->esq = newNode(5);
    raiz->dir = newNode(7);
    raiz->esq->esq = newNode(3);
    raiz->esq->dir = newNode(8);
    raiz->dir->esq = newNode(1);
    raiz->dir->dir = newNode(6);
    raiz->esq->dir->esq = newNode(4);
    raiz->dir->esq->dir = newNode(9);

    printf("Caminhamento em ordem: ");
    em_ordem(raiz);
    printf("\n");

    return 0;
} 