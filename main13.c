#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nome[100001];
    char sigla[4];
    scanf("%s", nome);
    scanf("%s", sigla);

    // Transformar nome em maiúsculo
    for (int i = 0; nome[i] != '\0'; i++)
    {
        nome[i] = toupper(nome[i]);
    }

    int tamSigla = 3;

    if (sigla[2] == 'X')
    {
        tamSigla = 2;
    }

    int i = 0, j = 0;
    while (nome[i] != '\0' && j < tamSigla)
    {
        if (nome[i] == sigla[j])
        {
            j++;
        }
        i++;
    }

    if (j == tamSigla)
        printf("Sim\n");
    else
        printf("Nao\n");

    return 0;
}
