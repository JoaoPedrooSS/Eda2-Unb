#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int e, int d)
{
    int pivo = v[d];
    int j = e;
    int t;
    for (int i = e; i < d; i++)                                 //v[i] = 7 v[j] = 31
    {
        if (v[i] < pivo)                                        //[17 5 7 9 12 21 31]
        {
            t = v[j];
            v[j] = v[i];
            v[i] = t;
            j++;
        }
    }
    t = v[d];
    v[d] = v[j];
    v[j] = t;
    return j;
}

void quicksort(int *v, int e, int d)
{
    if (e < d)
    {
        int p = particiona(v, e, d);
        quicksort(v, e, p - 1);
        quicksort(v, p + 1, d);
    }
}

void quickSelect(int *vetor, int inicio, int fim, int indice)
{
    if (inicio >= fim)
    {
        return;
    }
    int pivo = particiona(vetor, inicio, fim);
    if (indice < pivo)
    {
        quickSelect(vetor, inicio, pivo - 1, indice);
    }
    else if (indice > pivo)
    {
        quickSelect(vetor, pivo + 1, fim, indice);
    }
}
void imprimeTopN(int *v, int n, int m)
{
    quickSelect(v, 0, n, n - m);
    quicksort(v, n - m + 1, n);

    for (int i = n - m; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int main()
{
    int vetor[8] = {9, 7, 6, 1, 3, 4, 2, 5};

    imprimeTopN(vetor,8,3);
}