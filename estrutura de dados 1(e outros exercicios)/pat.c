#include <stdio.h>

int main()
{
    int P = 0, Pcopy = 0;
    char mapa[1001][1001] = {};

    int linha = 0, coluna = 0;
    int SLinha = 0, SColuna = 0;
    scanf("%d", &P);

    Pcopy = P;
    int linhas = 0, colunas = 0, tmp_colunas = 0;

    while (scanf("%c", &mapa[linha][coluna]) != EOF)
    {
        if (mapa[linha][coluna] == 'S')
        {
            SLinha = linha;
            SColuna = coluna;
        }
        if (mapa[linha][coluna] != '\n')
        {
            coluna++;
            tmp_colunas++;
        }
        else
        {
            if (tmp_colunas > colunas)
            {
                colunas = tmp_colunas;
            }
            tmp_colunas = 0;
            coluna = 0;
            linha++;
            linhas++;
        }
    }

    int i = SLinha, j = SColuna;

    while (mapa[i][j] != 'E')
    {
        if (i <= linhas && j <= colunas)
        {
            if (mapa[i][j + 1] == '_')
            {
                j++;
                mapa[i][j] = '#';
            }
            if (mapa[i][j - 1] == '_')
            {
                j--;
                mapa[i][j] = '#';
            }
            if (mapa[i + 1][j] == '_')
            {
                i++;
                mapa[i][j] = '#';
            }
            if (mapa[i - 1][j] == '_')
            {
                i--;
                mapa[i][j] = '#';
            }
            //---------------
            if (mapa[i][j + 1] == 'o')
            {
                P--;
                j++;
                mapa[i][j] = '#';
            }
            if (mapa[i][j - 1] == 'o')
            {
                P--;
                j--;
                mapa[i][j] = '#';
            }
            if (mapa[i + 1][j] == 'o')
            {
                P--;
                i++;
                mapa[i][j] = '#';
            }
            if (mapa[i - 1][j] == 'o')
            {
                P--;
                i--;
                mapa[i][j] = '#';
            }
            //--------------------------------
            if (mapa[i][j + 1] == 'E')
            {
                j++;
                break;
            }
            if (mapa[i][j - 1] == 'E')
            {
                j--;
                break;
            }
            if (mapa[i + 1][j] == 'E')
            {
                i++;
                break;
            }
            if (mapa[i - 1][j] == 'E')
            {
                i--;
                break;
            }
        }
    }

    if (Pcopy == P)
    {
        printf("Nenhum morreu :(\n");
    }
    else if (P < Pcopy && P != 0)
    {
        printf("%d encontraram o vovo\n", P);
    }
    else
    {
        printf("Todos morreram :)\n");
    }
    return 0;
}