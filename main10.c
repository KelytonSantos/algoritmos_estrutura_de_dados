#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char letra;
    int quantidade;
} Composition;

int compara_string(char *str, Composition *comp);
void sanitizacao(char *str);

int main()
{
    int n = 0;
    scanf("%d%*c", &n); // lê n e descarta o '\n'

    char *str1 = malloc((n + 2) * sizeof(char));
    char *str2 = malloc((n + 2) * sizeof(char));

    if (str1 == NULL || str2 == NULL)
    {
        // printf("Erro de alocação\n");
        return 1;
    }

    fgets(str1, n + 2, stdin);
    fgets(str2, n + 2, stdin);

    Composition *comp1 = malloc((n + 2) * sizeof(Composition));
    Composition *comp2 = malloc((n + 2) * sizeof(Composition));

    sanitizacao(str1);
    int qtd1 = compara_string(str1, comp1);

    sanitizacao(str2);
    int qtd2 = compara_string(str2, comp2);

    int eh_anagrama = 1;
    if (qtd1 != qtd2)
    {
        eh_anagrama = 0;
    }
    else
    {
        for (int i = 0; i < qtd1; i++)
        {
            int encontrado = 0;
            for (int j = 0; j < qtd2; j++)
            {
                if ((comp1[i].letra == comp2[j].letra) &&
                    (comp1[i].quantidade == comp2[j].quantidade))
                {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                eh_anagrama = 0;
                break;
            }
        }
    }

    // printf("é anagrama: %d\n", eh_anagrama);

    if (eh_anagrama)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    // printf("String 1: %s\n", str1);
    // printf("String 2: %s\n", str2);

    free(str1);
    free(str2);
    free(comp1);
    free(comp2);
    return 0;
}

int compara_string(char *str, Composition *comp)
{
    int i, j, counter, contador_comp = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        int ja_existe = 0;
        for (j = 0; j < contador_comp; j++)
        {
            if (comp[j].letra == str[i])
            {
                ja_existe = 1;
                break;
            }
        }
        if (ja_existe)
            continue;

        counter = 0;
        for (j = 0; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
                counter++;
        }

        comp[contador_comp].letra = str[i];
        comp[contador_comp].quantidade = counter;

        contador_comp++;
    }

    return contador_comp;
}

void sanitizacao(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == ' ')
            str[i] = '_';
    }
}
