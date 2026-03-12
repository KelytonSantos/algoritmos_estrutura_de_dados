#include <stdio.h>
#define TAM_MAX 1001

char mapa[TAM_MAX][TAM_MAX];
int x = 0, y = 0;
int posit_x_s = 0, posit_y_s = 0, numero_maximo_colunas = 0;
int P = 0;
int P_Copy = 0;

void dfs(int linha, int coluna);

int main()
{
    char caracter;

    scanf("%d", &P);

    P_Copy = P;

    while (scanf("%c", &caracter) != EOF)
    {
        if (caracter == 'S')
        {
            posit_x_s = x;
            posit_y_s = y;
        }

        mapa[x][y] = caracter;

        if (caracter == '\n')
        {
            x++;
            numero_maximo_colunas = (y > numero_maximo_colunas) ? y : numero_maximo_colunas;
            y = 0;
        }
        else
        {
            y++;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < numero_maximo_colunas; j++)
        {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }

    dfs(posit_x_s, posit_y_s);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < numero_maximo_colunas; j++)
        {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }

    if (P_Copy == P)
    {
        printf("Nenhum morreu :(\n");
    }
    else if (P < P_Copy && P != 0)
    {
        printf("%d encontraram o vovo\n", P);
    }
    else
    {
        printf("Todos morreram :)\n");
    }

    return 0;
}

void dfs(int linha, int coluna)
{
    // printf("i\n");
    if (mapa[linha][coluna] == 'E')
        return;

    if (mapa[linha][coluna] == 'o')
        P--;

    mapa[linha][coluna] = '#';

    // testa ate a borda da ultima linha
    if (linha < x && mapa[linha + 1][coluna] != '#' && (mapa[linha + 1][coluna] == 'o' || mapa[linha + 1][coluna] == '_'))
        dfs(linha + 1, coluna);

    // testa ate a borda da primeira linha
    if (linha > 0 && mapa[linha - 1][coluna] != '#' && (mapa[linha - 1][coluna] == 'o' || mapa[linha - 1][coluna] == '_'))
        dfs(linha - 1, coluna);

    // testa ate a borda da ultima coluna
    if (coluna < y && mapa[linha][coluna + 1] != '#' && (mapa[linha][coluna + 1] == 'o' || mapa[linha][coluna + 1] == '_'))
        dfs(linha, coluna + 1);

    // testa ate a borda da primeira coluna
    if (coluna > 0 && mapa[linha][coluna - 1] != '#' && (mapa[linha][coluna - 1] == 'o' || mapa[linha][coluna - 1] == '_'))
        dfs(linha, coluna - 1);
}

/*
    x = linha, y = coluna

    x++, y = baixo
    x--, y = cima
    x  , y++ = direita
    x  , y-- = esquerda

*/