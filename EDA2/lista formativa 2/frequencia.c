#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frequecia
{
    int codigo;
    int qtd_codigo;
} frequecia;

// Função de comparação para qsort:
// - ordena por qtd_codigo em ordem crescente
// - se qtd_codigo for igual, ordena por codigo em ordem crescente
int cmpFreq(const void *a, const void *b)
{
    const frequecia *fa = (const frequecia *)a;
    const frequecia *fb = (const frequecia *)b;
    if (fa->qtd_codigo != fb->qtd_codigo)
    {
        return fa->qtd_codigo - fb->qtd_codigo;
    }
    return fa->codigo - fb->codigo;
}

int main()
{
    char frase[1001];
    // Lê enquanto houver entrada
    while (scanf("%s", frase) != EOF)
    {
        // Contagem de caracteres
        int cont[127] = {0};

        for (int i = 0; frase[i] != '\0'; i++)
        {
            cont[(unsigned char)frase[i]]++;
        }

        // Monta o vetor de frequência
        frequecia vs[127];
        int tam = 0;

        for (int i = 0; i < 127; i++)
        {
            if (cont[i] > 0)
            {
                vs[tam].codigo = i;
                vs[tam].qtd_codigo = cont[i];
                tam++;
            }
        }

        // Ordena usando qsort
        qsort(vs, tam, sizeof(frequecia), cmpFreq);

        // Imprime o resultado
        for (int i = 0; i < tam; i++)
        {
            printf("%d %d\n", vs[i].codigo, vs[i].qtd_codigo);
        }
        printf("\n");
    }
    return 0;
}