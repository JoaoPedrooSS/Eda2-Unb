#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *Nome = (char *)malloc(100001 * sizeof(char));

    if (Nome == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    fgets(Nome, 100001, stdin);

    char sigla[3];

    for (int i = 0; i < 3; i++)
    {
        char a;
        scanf("%c", &a);
        sigla[i] = tolower(a);
    };

    int cont = 0;
    for (int i = 0; i < strlen(Nome); i++)
    {
        if (sigla[cont] == Nome[i])
        {
            cont++;
        };
    };
    if (sigla[2] == 'x'){
        cont++;
    }
    if (cont < 3)
    {
        printf("Nao");
    }
    else
    {
        printf("Sim");
    };
    free(Nome);

    return 0;
}
