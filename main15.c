#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    int qtd_reprovado;
} Materia;

int *organiza(Materia *composit, int tamanho, int *tamanho_vetor_final);
void bubble(int *vet, int tamanho);

int main()
{
    int D = 0, ano = 0, semestre = 0, quantidade_de_materias;
    int codigo_materia = 0, matriculados = 0, aprovados = 0, reprovados = 0;

    scanf("%d", &D);

    while (scanf("%d %d %d", &ano, &semestre, &quantidade_de_materias) != EOF)
    {
        Materia *composit = malloc(quantidade_de_materias * sizeof(Materia));

        for (int i = 0; i < quantidade_de_materias; i++)
        {
            scanf("%d %d %d", &codigo_materia, &matriculados, &aprovados);
            reprovados = matriculados - aprovados;
            composit[i].codigo = codigo_materia;
            composit[i].qtd_reprovado = reprovados;
        }

        int tamanho_final = 0;
        int *vet = organiza(composit, quantidade_de_materias, &tamanho_final);

        printf("%d/%d\n", ano, semestre);

        for (int i = 0; i < tamanho_final; i++)
        {
            printf("%d ", vet[i]);
        }
        printf("\n");
        printf("\n");

        free(composit);
        free(vet);
    }

    return 0;
}

int *organiza(Materia *composit, int tamanho, int *tamanho_vetor_final)
{
    int maior_reprovacao = 0;
    int contador = 1;

    for (int i = 0; i < tamanho; i++)
    {
        if (maior_reprovacao <= composit[i].qtd_reprovado)
        {
            maior_reprovacao = composit[i].qtd_reprovado;
        }
    }

    int *vetor_de_materias = malloc(sizeof(int));
    int contador_vetor_de_materiais = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (maior_reprovacao <= composit[i].qtd_reprovado)
        {
            maior_reprovacao = composit[i].qtd_reprovado;
            contador++;

            vetor_de_materias = realloc(vetor_de_materias, contador * sizeof(int));

            vetor_de_materias[contador_vetor_de_materiais++] = composit[i].codigo;
            // printf("teste: %d\n", composit[i].codigo);
        }
    }

    bubble(vetor_de_materias, contador - 1);

    *tamanho_vetor_final = contador - 1;

    return vetor_de_materias;
}

void bubble(int *vet, int tamanho)
{
    int temp = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}
/*
ideia inicial, passar o materia pra ca, depois acha as maiores e iguais reprovaçoes depois, pega as materias e faz o sort
*/