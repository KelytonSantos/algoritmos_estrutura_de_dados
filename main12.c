#include <stdio.h>
#include <stdlib.h>

void organiza_vetor(int *vet_materias, int tamanho);
int main()
{

    int D = 0;
    scanf("%d", &D);

    int ano = 0, semestre = 0, quantidade_de_disciplinas = 0;

    while (scanf("%d %d %d", &ano, &semestre, &quantidade_de_disciplinas) != EOF)
    {
        int *vetor_de_materias = malloc(sizeof(int) * quantidade_de_disciplinas);

        int codigo_da_materia = 0, alunos_matriculados = 0, alunos_aprovados = 0;
        int reprovados = 0;
        int max_reprovados = -1; // começa em -1 pra garantir que a 1ª matéria entre
        int contador = 0;

        for (int i = 0; i < quantidade_de_disciplinas; i++)
        {
            scanf("%d %d %d", &codigo_da_materia, &alunos_matriculados, &alunos_aprovados);

            reprovados = alunos_matriculados - alunos_aprovados;

            if (reprovados > max_reprovados)
            {
                // achamos um novo máximo → atualiza
                max_reprovados = reprovados;

                // zera a lista e começa de novo
                contador = 0;
                vetor_de_materias[contador++] = codigo_da_materia;
            }
            else if (reprovados == max_reprovados)
            {
                // empate → acrescenta
                vetor_de_materias[contador++] = codigo_da_materia;
            }
            // se for menor, ignora
        }

        organiza_vetor(vetor_de_materias, quantidade_de_disciplinas);

        printf("%d/%d\n", ano, semestre);
        for (int i = 0; i < quantidade_de_disciplinas; i++)
        {
            if (vetor_de_materias[i] != 0)
                printf("%d ", vetor_de_materias[i]);
        }

        printf("\n");
        printf("\n");
        free(vetor_de_materias);
    }

    return 0;
}

void organiza_vetor(int *vet_materias, int tamanho)
{
    int temp = 0;

    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (vet_materias[j] > vet_materias[j + 1])
            {
                temp = vet_materias[j];
                vet_materias[j] = vet_materias[j + 1];
                vet_materias[j + 1] = temp;
            }
        }
    }
}

/*
achar um jeito de associar aquela materia;
*/