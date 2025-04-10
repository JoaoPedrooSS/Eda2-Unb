#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *proximo;
} No;

typedef struct lista
{
    No *inicio;
    int tam;
} Lista;

int hash(int chave, int n);
void inicializarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int valor)
{
    No *novo = malloc(sizeof(No));
    novo->chave = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->tam++;
}

int buscaLista(Lista *l, int valor, int n)
{
    No *aux = l->inicio;

    while (aux && aux->chave != valor)
    {
        aux = aux->proximo;
    }

    if (aux == NULL)
    {
        printf("Valor nao encontrado\n");
        return -1;
    }
    else
    {
        return hash(aux->chave, n);
    }
}
void removeLista(Lista *l, int valor, int n)
{
    No *aux = l->inicio;
    if(l->tam != 0){
        if(l->inicio->chave == valor){
            l->inicio = l->inicio->proximo;
        }else{
            while(aux->proximo && aux->proximo->chave != valor){
                aux = aux->proximo;
            }
            if(aux->proximo == NULL){
                printf("Valor nao encontrado\n");
            }else if (aux->proximo->chave == valor){
                aux->proximo = aux->proximo->proximo;
                printf("Valor removido com sucesso!\n");
            }
        }
    }else{
        printf("A lista esta vazia!\n");
    }
}

void imprimeLista(Lista *l)
{
    No *aux = l->inicio;
    printf("Tam: %d\n", l->tam);
    while (aux)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
    printf("\n");
}

void inicializa(Lista *tabela, int n)
{
    for (int i = 0; i < n; i++)
        inicializarLista(&tabela[i]);
}

int hash(int chave, int n)
{
    return chave % n;
}

void inserir(Lista *tabela, int valor, int n)
{
    int id = hash(valor, n);
    inserirLista(&tabela[id], valor);
}

int buscar(Lista *tabela, int valor, int n)
{
    int id = hash(valor, n);
    buscaLista(&tabela[id], valor, n);
}

void imprimir(Lista tabela[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("indice %d = ", i);
        imprimeLista(&tabela[i]);
    }
    printf("\n");
}
void remover(Lista tabela[], int valor, int n){
    int id = hash(valor, n);
    removeLista(&tabela[id], valor, n);
}
int main()
{
    int n = 11;
    int d, i;
    Lista tabela[n];

    inicializa(tabela, n);

    while (i != 'S')
    {
        printf(" 0 => inserir\n 1 => buscar\n 2 => printar lista\n 3 => remover\n");
        scanf("%d", &i);
        switch (i)
        {
        case 0:
            scanf("%d", &d);
            inserir(tabela, d, n);
            break;
        case 1:
            scanf("%d", &d);
            if (buscar(tabela, d, n) != -1)
            {
                printf("indice: %d\n", buscar(tabela, d, n));
            }else{
                break;
            }
            break;
        case 2:
            imprimir(tabela, n);
            break;
        case 3:
            scanf("%d", &d);
            remover(tabela, d, n);
            break;
        }
    }
}