#include <stdio.h>

struct tipoBanda
{
    char nome[80];
    int ano;
};

struct tipoShow
{
    char nome[80];
    int qtd;
    struct tipoBanda bandas[100];
};

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

void pesquisarNomeBanda(char pesquisa[80], struct tipoShow shows[50], int n)
{
    int founded = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < shows[i].qtd; j++)
        {
            if (strcmp(shows[i].bandas[j].nome, pesquisa) == 0)
            {
                printf("%s : ano %d\n", shows[i].nome, shows[i].bandas[j].ano);
                founded = 1;
            }
        }
    }

    if (!founded)
    {
        printf("Banda nao cadastrada\n");
    }
}