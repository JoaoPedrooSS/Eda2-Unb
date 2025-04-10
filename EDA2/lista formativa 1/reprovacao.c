#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

struct Disciplinas
{
    int codigo;
    int alunos;
    int aprovados;
    int reprovacao;
};

struct Semestre
{
    int ano;
    int semestre;
    int qtd_disciplinas;
    struct Disciplinas *disciplinas;
};

int main()
{
    struct Semestre *semestres = NULL;
    int ano, sem, qtdDisciplina;
    int numero_de_semestres = 0;
    int n;
    scanf("%d", &n);

    while (scanf("%d %d %d", &ano, &sem, &qtdDisciplina) != EOF)
    {
        struct Semestre semestre = {ano, sem, qtdDisciplina};

        semestre.disciplinas = malloc(semestre.qtd_disciplinas * sizeof(struct Disciplinas));

        for (int j = 0; j < semestre.qtd_disciplinas; j++)
        {
            scanf("%d", &semestre.disciplinas[j].codigo);
            scanf("%d", &semestre.disciplinas[j].alunos);
            scanf("%d", &semestre.disciplinas[j].aprovados);
            semestre.disciplinas[j].reprovacao = semestre.disciplinas[j].alunos - semestre.disciplinas[j].aprovados;
        }
        struct Semestre *temp = realloc(semestres, (numero_de_semestres + 1) * sizeof(struct Semestre));

        semestres = temp;
        semestres[numero_de_semestres] = semestre;
        numero_de_semestres++;
    }
    for (int i = 0; i < numero_de_semestres; i++)
    {
        int maior = 0;
        int cont = 0;
        for (int j = 0; j < semestres[i].qtd_disciplinas; j++)
        {
            if (semestres[i].disciplinas[j].reprovacao >= maior)
            {
                maior = semestres[i].disciplinas[j].reprovacao;
            }
        }

        for (int j = 0; j < semestres[i].qtd_disciplinas; j++)
        {
            if (semestres[i].disciplinas[j].reprovacao == maior)
            {
                cont++;
            }
        }
        printf("%d/%d\n", semestres[i].ano, semestres[i].semestre);

        int *mais_reps = (int *)malloc(cont * sizeof(int));

        int index = 0;
        for (int j = 0; j < semestres[i].qtd_disciplinas; j++)
        {
            if (semestres[i].disciplinas[j].reprovacao == maior)
            {
                mais_reps[index] = semestres[i].disciplinas[j].codigo;
                index++;
            }
        }

        qsort(mais_reps, cont, sizeof(int), comparar);

        for (int j = 0; j < cont; j++)
        {
            printf("%d ", mais_reps[j]);
        };
        printf("\n");
    }

    for (int i = 0; i < numero_de_semestres; i++)
    {
        free(semestres[i].disciplinas);
    }
    free(semestres);
}
