#include <stdio.h>
#include <stdlib.h>

// Função de partição para o QuickSort
int particiona(int *v, int e, int d)
{
    int pivo = v[d];
    int i = e - 1;
    int t;

    for (int j = e; j < d; j++)
    {
        if (v[j] < pivo)
        {
            i++;
            // Troca os elementos
            t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    // Coloca o pivô na posição correta
    t = v[i + 1];
    v[i + 1] = v[d];
    v[d] = t;

    return i + 1; // Retorna a posição do pivô
}

// Função QuickSort
void quicksort(int *v, int e, int d)
{
    if (e < d)
    {
        int p = particiona(v, e, d);
        quicksort(v, e, p - 1); // Lado esquerdo
        quicksort(v, p + 1, d); // Lado direito
    }
}

// Função de merge para o MergeSort
void merge(int *v, int inicio, int meio, int fim)
{
    int tamanho = fim - inicio + 1;
    int *novo = (int *)malloc(tamanho * sizeof(int));
    int a = inicio, b = meio + 1, x = 0;

    while (a <= meio && b <= fim)
    {
        if (v[a] <= v[b])
        {
            novo[x++] = v[a++];
        }
        else
        {
            novo[x++] = v[b++];
        }
    }

    // Copia os elementos restantes
    while (a <= meio)
    {
        novo[x++] = v[a++];
    }
    while (b <= fim)
    {
        novo[x++] = v[b++];
    }

    // Copia de volta para o vetor original
    for (int i = 0; i < tamanho; i++)
    {
        v[inicio + i] = novo[i];
    }

    free(novo);
}

// Função MergeSort
void mergesort(int *v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

// Função para imprimir o vetor
void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função principal
int main()
{
    int v[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    imprimeVetor(v, n);

    // Testando QuickSort
    quicksort(v, 0, n - 1);
    printf("Vetor ordenado (QuickSort): ");
    imprimeVetor(v, n);

    // Reinicializa o vetor
    int v2[] = {10, 7, 8, 9, 1, 5};
    printf("Vetor original: ");
    imprimeVetor(v2, n);

    // Testando MergeSort
    mergesort(v2, 0, n - 1);
    printf("Vetor ordenado (MergeSort): ");
    imprimeVetor(v2, n);

    return 0;
}
