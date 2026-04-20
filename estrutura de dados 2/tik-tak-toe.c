#include <stdio.h>
#include <stdlib.h>

typedef struct Player
{
    char opt;
    int player;

} Player;

int isMatP(char mat[][3], int n, int m)
{
    int preenchida = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '_')
            {
                preenchida = 1;
                break;
            }
        }
    }

    return preenchida;
}

void printMat(char mat[][3], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '_')
            {
                printf("_ ");
            }
            else
            {
                printf("%c ", mat[i][j]);
            }
        }
        printf("\n");
    }
}

void condicaoDeVitoria(char mat[][3], int n, int m)
{

    int contX = 0;
    int contO = 0;
    char letraganhadora;

    for (int i = 0; i < 3; i++)
    {
        if (mat[i][0] == 'X')
        { // Fixamos a coluna 0 (primeira)
            contX++;
        }
        else if (mat[i][0] == 'O')
        {
            contO++;
        }
    }

    if (contX == 3)
        letraganhadora = 'X';
    if (contO == 3)
        letraganhadora = 'O';
}

void chooseElement(Player *player)
{
    printf("Digite a escolha: O (bola) ou X: \n");
    scanf(" %c", &player[0].opt);
    player[0].player = 1;

    if (player[0].opt == 'X' || player[0].opt == 'x')
    {
        player[1].opt = 'O';
    }
    else
    {
        player[1].opt = 'X';
    }

    printf("O player 2 ficou com: %c\n", player[1].opt);
    // printf("%c\n", player[1].opt);
}

void insertElement(Player *player, char mat[][3], int n, int m)
{
    char opt1 = player[0].opt;
    char opt2 = player[1].opt;

    int x = 0;
    int y = 0;

    while (isMatP(mat, 3, 3))
    {
        printf("Player 1 digite as coordenadas do primeiro elemento [0-2][0-2]\n");

        scanf("%d %d", &x, &y);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[x][y] = opt1;
            }
        }

        printMat(mat, 3, 3);

        printf("Player 2 digite as coordenadas do primeiro elemento [0-2][0-2]\n");

        scanf("%d %d", &x, &y);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[x][y] = opt2;
            }
        }

        printMat(mat, 3, 3);
    }
}

int main()
{
    Player *players = (Player *)malloc(sizeof(Player) * 2);

    char mat[3][3] = {'_', '_', '_',
                      '_', '_', '_',
                      '_', '_', '_'};

    char e1;
    chooseElement(players);

    insertElement(players, mat, 3, 3);

    printMat(mat, 3, 3);

    // printf("%c\n", players[0].opt);

    free(players);
    return 0;
}