#include <stdio.h>

int main()
{
    char letra;
    int numero;

    int n, m, contador = 0;
    int vetor_linha[26], vetor_coluna[20];

    scanf("%d %d", &n, &m);
    char mapa[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mapa[i][j] = 0;
        }
    }

    while (scanf(" %c%d", &letra, &numero) != EOF)
    {
        int linha = letra - 'A';
        int coluna = numero - 1;
        if (linha < n && coluna < m)
        {
            mapa[linha][coluna] = 1;
        }
    }

    printf("   ");
    for (int j = 0; j < m; j++)
    {
        printf("%02d ", j + 1);
    }
    printf("\n");

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < m; j++)
        {
            if (mapa[i][j] == 1)
                printf("XX ");
            else
                printf("-- ");
        }
        printf("\n");
    }

    return 0;
}
