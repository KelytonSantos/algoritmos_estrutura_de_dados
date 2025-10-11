#include <stdio.h>

int atoi(const char *str)
{
    int num = 0;

    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

void strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

void bubble_sort(int *vet, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                int temp = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

int binary_search(int *v, int indice_esquerdo, int indice_direito, int x)
{

    if (indice_esquerdo < indice_direito - 1)
    {
        int m = (indice_esquerdo + indice_direito) / 2;

        if (v[m] >= x)
            return binary_search(v, indice_esquerdo, m, x);
        else
            return binary_search(v, m, indice_direito, x);
    }
    return indice_direito;
}

int interface(int *vet, int n, int x)
{
    return binary_search(vet, -1, n, x);
}

int main()
{

    printf("%d\n", atoi("198020"));
    return 0;
}