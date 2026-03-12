#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vet, int n)
{
    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        int x = vet[j];

        while (i >= 0 && vet[i] > x)
        {
            vet[i + 1] = vet[i];
            i--;
        }
        vet[i + 1] = x;
    }
}

int busca_binaria(int *vet, int n, int x)
{
    int e = 0, d = n - 1;

    while (e <= d)
    {
        int m = (e + d) / 2;

        if (vet[m] == x)
        {
            return m;
        }
        else if (vet[m] < x)
        {
            e = m + 1;
        }
        else
        {
            d = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 0, chave = 0;

    scanf("%d %d", &n, &chave);
    int *vet_original = malloc(sizeof(int) * n);
    int *vet_ordenado = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet_original[i]);
        vet_ordenado[i] = vet_original[i];
    }

    insertion_sort(vet_ordenado, n);

    int indice_chave = busca_binaria(vet_ordenado, n, chave);

    int *nova_lista = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        nova_lista[i] = vet_original[(indice_chave + i) % n];
    }

    printf("%d\n", indice_chave);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nova_lista[i]);
    }
    printf("\n");

    free(vet_original);
    free(vet_ordenado);
    free(nova_lista);

    return 0;
}