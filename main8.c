#include <stdio.h>

char mapa[1001][1001];
int linhas = 0;
int colunas = 0;
int po, p;

void dfs(int x, int y)
{
    if (mapa[x][y] == 'E')
        return;
    if (mapa[x][y] == 'o')
        p--;
    mapa[x][y] = '#';
    if (p == 0)
        return;
    if (x < linhas && mapa[x + 1][y] != '#')
        return dfs(x + 1, y);
    if (x > 0 && mapa[x - 1][y] != '#')
        return dfs(x - 1, y);
    if (y < colunas && mapa[x][y + 1] != '#')
        return dfs(x, y + 1);
    if (y > 0 && mapa[x][y - 1] != '#')
        return dfs(x, y - 1);

    return;
}

int main()
{
    int temp_cols = 0;
    char ch;
    int xi = 0, yi = 0;

    if (scanf("%d", &po) != 1)
    {
        return 1;
    }
    p = po;
    scanf("%c", &ch);

    while (scanf("%c", &ch) == 1)
    {
        if (ch == '\n')
        {
            if (linhas == 0)
            {
                colunas = temp_cols;
            }
            mapa[linhas][temp_cols] = '\0';
            linhas++;
            temp_cols = 0;
        }
        else
        {
            if (ch == 'S')
            {
                xi = linhas;
                yi = temp_cols;
            }
            mapa[linhas][temp_cols] = ch;
            temp_cols++;
        }
    }
    linhas--;
    colunas--;

    dfs(xi, yi);

    if (p == 0)
        printf("Todos morreram :)\n");
    else if (p == po)
        printf("Nenhum morreu :(\n");
    else
        printf("%d encontraram o vovo\n", p);

    return 0;
}
