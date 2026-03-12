#include <stdio.h>
#include <stdlib.h>

int *intercala2(int *v1, int n1, int *v2, int n2, int *tamanho_resultado)
{
    int *resultado = malloc(sizeof(int) * (n1 + n2));
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            resultado[k++] = v1[i++];
        }
        else
        {
            resultado[k++] = v2[j++];
        }
    }

    while (i < n1)
    {
        resultado[k++] = v1[i++];
    }

    while (j < n2)
    {
        resultado[k++] = v2[j++];
    }

    *tamanho_resultado = n1 + n2;
    return resultado;
}

int *intercala8(int **vetores, int *tamanhos, int *tamanho_final)
{
    int *resultado = NULL;
    int tamanho_atual = 0;

    // Começa com o primeiro vetor
    if (tamanhos[0] > 0)
    {
        resultado = malloc(sizeof(int) * tamanhos[0]);
        for (int i = 0; i < tamanhos[0]; i++)
        {
            resultado[i] = vetores[0][i];
        }
        tamanho_atual = tamanhos[0];
    }
    else
    {
        resultado = malloc(sizeof(int) * 1); // Vetor vazio
        tamanho_atual = 0;
    }

    // Intercala com os outros 7 vetores
    for (int i = 1; i < 8; i++)
    {
        if (tamanhos[i] > 0)
        {
            int novo_tamanho;
            int *novo_resultado = intercala2(resultado, tamanho_atual,
                                             vetores[i], tamanhos[i],
                                             &novo_tamanho);
            free(resultado);
            resultado = novo_resultado;
            tamanho_atual = novo_tamanho;
        }
    }

    *tamanho_final = tamanho_atual;
    return resultado;
}

int main()
{
    int *vetores[8];
    int tamanhos[8];

    // Lê os 8 conjuntos de dados
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &tamanhos[i]);

        if (tamanhos[i] > 0)
        {
            vetores[i] = malloc(sizeof(int) * tamanhos[i]);
            for (int j = 0; j < tamanhos[i]; j++)
            {
                scanf("%d", &vetores[i][j]);
            }
        }
        else
        {
            vetores[i] = malloc(sizeof(int) * 1); // Vetor vazio
        }
    }

    // Intercala todos os vetores
    int tamanho_final;
    int *resultado = intercala8(vetores, tamanhos, &tamanho_final);

    // Imprime o resultado
    for (int i = 0; i < tamanho_final; i++)
    {
        printf("%d", resultado[i]);
        if (i < tamanho_final - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // Libera a memória
    for (int i = 0; i < 8; i++)
    {
        free(vetores[i]);
    }
    free(resultado);

    return 0;
}