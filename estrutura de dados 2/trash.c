#include <stdio.h>

void insertion_sort(int *vet, int n)
{
    for (int j = 1; j < n; j++)
    {

        int x = vet[j];
        int i = j - 1;

        while (i >= 0 && vet[i] > x)
        {
            vet[i + 1] = vet[i];
            i--;
        }
        vet[i + 1] = x;
    }
}

void printa(int *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void troca(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selection_sort(int *vet, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[min] > vet[j])
                min = j;
        }
        troca(&vet[min], &vet[i]);
    }
}

int separa(int *vet, int e, int d)
{
    int j = e; //
    int k = e;
    int p = vet[d];

    while (k < d)
    {
        if (vet[k] <= p)
        {
            int tmpo = vet[k];
            vet[k] = vet[j];
            vet[j] = tmpo;
            j++;
        }
        k++;
    }

    vet[d] = vet[j];
    vet[j] = p;
    return j;
}

int main()
{
    int vet[6] = {6, 4, 2, 5, 3, 1};
    int n = 6;

    // insertion_sort(vet, n);
    selection(vet, n);
    printa(vet, n);
    return 0;
}
