#include <stdio.h>

int bb(int *v, int esquerdo, int direito, int x)
{
    if (esquerdo < direito - 1)
    {
        int m = (direito + esquerdo) / 2;

        if (v[m] >= x)
        {
            return bb(v, esquerdo, m, x);
        }
        else
        {
            return bb(v, m, direito, x);
        }
    }
    return direito;
}

int interface(int *vet, int n, int x)
{

    int j = bb(vet, -1, n, x);
    return j;
}

int main()
{

    int vet[] = {0, 1, 2, 4, 5};
    int n = 5;
    int x = 3;

    int result = interface(vet, n, x);
    printf("%d\n", result);

    return 0;
}