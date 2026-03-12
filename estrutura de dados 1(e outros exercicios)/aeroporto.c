#include <stdio.h>

void maiusculo(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
}

void valida(char *nome, char *sigla)
{
    int verificar_x = (sigla[2] == 'X');
    int tamanho_sigla = verificar_x ? 2 : 3;

    int indice_nome = 0;
    int encontradas = 0;

    for (int i = 0; i < tamanho_sigla; i++)
    {
        while (nome[indice_nome] != '\0')
        {
            if (sigla[i] == nome[indice_nome])
            {
                encontradas++;
                indice_nome++;
                break;
            }
            indice_nome++;
        }
    }

    if (encontradas == tamanho_sigla)
    {
        printf("Sim\n");
    }
    else
    {
        printf("Nao\n");
    }
}

int main()
{
    char nome[100001];
    char sigla[4];

    scanf("%s", nome);
    scanf("%s", sigla);

    maiusculo(nome);
    valida(nome, sigla);

    return 0;
}