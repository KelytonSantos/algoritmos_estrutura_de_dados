#include <stdio.h>

int main()
{
    char mapa[1000][1001];
    int P = 0, P_copy = 0;
    int linha = 0, coluna = 0;
    int salva_tamanho_coluna = 0;
    int posit_E_i = 0, posit_E_j = 0;

    scanf("%d\n", &P);

    P_copy = P;

    while (scanf("%c", &mapa[linha][coluna]) != EOF)
    {
        if (mapa[linha][coluna] != '\n')
        {
            coluna++;
        }
        else
        {
            salva_tamanho_coluna = coluna;
            linha++;
            coluna = 0;
        }
    }

    int i = -1, j = -1;
    for (int x = 0; x < linha; x++)
    {
        for (int y = 0; y < salva_tamanho_coluna; y++)
        {
            if (mapa[x][y] == 'S')
            {
                i = x;
                j = y;
                break;
            }
        }
        if (i != -1)
            break;
    }

    int lin = i, col = j;
    while (1)
    {
        if (col + 1 < salva_tamanho_coluna && mapa[lin][col + 1] == '_')
        {
            col++;
            mapa[lin][col] = '#';
        }
        else if (col - 1 >= 0 && mapa[lin][col - 1] == '_')
        {
            col--;
            mapa[lin][col] = '#';
        }
        else if (lin + 1 < linha && mapa[lin + 1][col] == '_')
        {
            lin++;
            mapa[lin][col] = '#';
        }
        else if (lin - 1 >= 0 && mapa[lin - 1][col] == '_')
        {
            lin--;
            mapa[lin][col] = '#';
        }
        else if (col + 1 < salva_tamanho_coluna && mapa[lin][col + 1] == 'o')
        {
            P--;
            col++;
            mapa[lin][col] = '#';
        }
        else if (col - 1 >= 0 && mapa[lin][col - 1] == 'o')
        {
            P--;
            col--;
            mapa[lin][col] = '#';
        }
        else if (lin + 1 < linha && mapa[lin + 1][col] == 'o')
        {
            P--;
            lin++;
            mapa[lin][col] = '#';
        }
        else if (lin - 1 >= 0 && mapa[lin - 1][col] == 'o')
        {
            P--;
            lin--;
            mapa[lin][col] = '#';
        }

        else if (col + 1 < salva_tamanho_coluna && mapa[lin][col + 1] == 'E')
        {
            col++;
            break;
        }
        else if (col - 1 >= 0 && mapa[lin][col - 1] == 'E')
        {
            col--;
            break;
        }
        else if (lin + 1 < linha && mapa[lin + 1][col] == 'E')
        {
            lin++;
            break;
        }
        else if (lin - 1 >= 0 && mapa[lin - 1][col] == 'E')
        {
            lin--;
            break;
        }
        else
        {
            break;
        }
    }

     if (P_copy == P)
    {
        printf("Nenhum morreu :(\n");
    }
    else if (P < P_copy && P != 0)
    {
        printf("%d encontraram o vovo\n", P);
    }
    else
    {
        printf("Todos morreram :)\n");
    }

    return 0;
}

/*
   printf("S: %d %d\n", i, j);

    for (int contI = 0; contI < linha; contI++)
    {
        for (int contJ = 0; contJ < salva_tamanho_coluna; contJ++)
        {
            printf("%c", mapa[contI][contJ]);
        }
        printf("\n");
    }

*/