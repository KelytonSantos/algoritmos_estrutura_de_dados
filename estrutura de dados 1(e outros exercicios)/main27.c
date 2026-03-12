#include <stdio.h>

void troca(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int particiona(int *vet, int e, int d)
{
    int j = e;
    int p = vet[d];

    for (int k = e; k <= d; k++)
    {
        if (vet[k] <= p)
        {
            troca(&vet[k], &vet[j++]);
        }
    }

    return j - 1;
}

void quick_sort(int *vet, int e, int d)
{
    if (e < d)
    {
        int j = particiona(vet, e, d);
        quick_sort(vet, e, j - 1);
        quick_sort(vet, j + 1, d);
    }
}

int main()
{

    int vet[] = {3, 8, 9, 4, 3, 0, 1};

    quick_sort(vet, 0, 6);

    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}