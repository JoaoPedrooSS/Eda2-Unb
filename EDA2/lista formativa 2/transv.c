#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore
typedef struct No
{
    char valor;
    struct No *esq;
    struct No *dir;
} No;

// Cria um novo nó com o caractere 'valor'
No *criarNo(char valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para encontrar a posição de 'valor' em 'inordem[]'
int buscarIndice(char inordem[], int inicio, int fim, char valor)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (inordem[i] == valor)
        {
            return i;
        }
    }
    return -1; // Não encontrado
}

// Função recursiva para construir a árvore
No *construirArvore(char preordem[], char inordem[],
                    int inicioInordem, int fimInordem,
                    int *indicePreordem)
{
    // Se não há elementos na subárvore, retorna NULL
    if (inicioInordem > fimInordem)
    {
        return NULL;
    }

    // O primeiro caractere de preordem[*indicePreordem] é a raiz_teste
    char valorRaiz = preordem[*indicePreordem];
    (*indicePreordem)++;

    // Cria nó para este valor
    No *raiz_teste = criarNo(valorRaiz);

    if (inicioInordem == fimInordem)
    {
        return raiz_teste;
    }

    int indiceRaiz = buscarIndice(inordem, inicioInordem, fimInordem, valorRaiz);

    raiz_teste->esq = construirArvore(preordem, inordem,
                                inicioInordem, indiceRaiz - 1,
                                indicePreordem);

    raiz_teste->dir = construirArvore(preordem, inordem,
                                indiceRaiz + 1, fimInordem,
                                indicePreordem);

    return raiz_teste;
}

void posOrdem(No *raiz_teste)
{
    if (raiz_teste == NULL)
    {
        return;
    }
    posOrdem(raiz_teste->esq);
    posOrdem(raiz_teste->dir);
    printf("%c", raiz_teste->valor);
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int n, indicePre = 0;
        scanf("%d", &n);
        char *preordem = (char *)malloc(sizeof(char) * n);
        char *emordem = (char *)malloc(sizeof(char) * n);
        scanf("%s", preordem);
        scanf("%s", emordem);
        No *raiz_teste = construirArvore(preordem, emordem, 0, n - 1, &indicePre);
        posOrdem(raiz_teste);
        printf("\n");
    }
    return 0;
}