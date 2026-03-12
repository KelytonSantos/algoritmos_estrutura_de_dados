#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int nivel;
    int status;
} Pokemon;

int main()
{
    int n = 0;
    scanf("%d", &n);

    Pokemon *pokemons = malloc(sizeof(Pokemon) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &pokemons[i].id, &pokemons[i].nivel, &pokemons[i].status);
    }

    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        Pokemon atual = pokemons[j];

        while (i >= 0)
        {
            if (pokemons[i].nivel < atual.nivel)
            {
                pokemons[i + 1] = pokemons[i];
                i--;
            }
            else if (pokemons[i].nivel == atual.nivel && pokemons[i].status < atual.status)
            {
                pokemons[i + 1] = pokemons[i];
                i--;
            }
            else
            {
                break;
            }
        }

        pokemons[i + 1] = atual;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%04d | %d | %d\n", pokemons[i].id, pokemons[i].nivel, pokemons[i].status);
    }

    free(pokemons);
    return 0;
}