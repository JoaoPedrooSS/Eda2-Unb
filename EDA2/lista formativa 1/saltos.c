#include <stdio.h>

void bubbleSort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void removerMaiorEMenor(double arr[], int *n)
{
    for(int i = 0; i < *n; i++){
        arr[i] = arr[i + 1];
    }
    *n -= 2;
}

double calculaNota(double arr[], double d){
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += arr[i];
    }
    total = ((total / 5) * d);

    return total;
}

int main()
{
    double d;
    scanf("%lf", &d);

    int tamanho = 7;
    double notas[tamanho];

    for (int i = 0; i < 7; i++)
    {
        scanf("%lf", &notas[i]);
    }

    bubbleSort(notas, tamanho);

    removerMaiorEMenor(notas, &tamanho);

    double resultado = calculaNota(notas, d);

    printf("%.1lf\n", resultado);
    return 0;
}