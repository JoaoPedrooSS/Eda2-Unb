#include <stdio.h>

int calculaMedia(int vet[], int n)
{
    long long int media = 0;

    for (int i = 0; i < n; i++)
    {
        media += vet[i];
    }

    media = (media / n);

    return media;
};

int main()
{
    int n;

    scanf("%d", &n);

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    long long int media = calculaMedia(vet, n);

    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > media)
        {
            contador++;
        }
    }
    if (contador > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (vet[i] > media)
            {
                printf("%d ", vet[i]);
            }
        }
    }else{
        printf("%d", contador);
    }

    return 0;
}