#include <stdio.h>

int imprimeTopN(int *v, int n, int m)
{
    int newVector[m];

    for (int i = 0; i < m; i++)
    {
        int maior = v[0];
        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] > maior)
            {
                maior = v[j];
                index = j;
            }
        }
        newVector[i] = maior;
        v[index] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d ", newVector[i]);
    }
}
int main()
{
    int v[] = {10, 5, 2, 6, 8, 9, 5, 6};

    imprimeTopN(v, 7, 3);

    return 0;
}