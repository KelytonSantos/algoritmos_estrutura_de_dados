#include <stdio.h>

void insertion_sort(int *vet, int n)
{
    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        int x = vet[j];

        // enquanto i for maior igual a 0 e vet na posit i for maior que vet na posit i+1(ex: 5, 4)
        while (i >= 0 && vet[i] > x)
        {
            //"joga pra frente" vet na posit i+1 vai ficar com o valor atual(ex: 5, 5)
            vet[i + 1] = vet[i];
            i--;
        }
        vet[i + 1] = x;
    }
}

void troca(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void selection_sort(int *vet, int n)
{
    // começa em 0
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        // começa em 1

        for (int j = i + 1; j < n; ++j)
        {
            // trava no valor do for de fora e compara com todos do 1 ao n vendo quem é o menor numero
            if (vet[min] > vet[j])
            {
                min = j;
            }
        }

        troca(&vet[i], &vet[min]);
    }
}

int main()
{
    int vet[] = {3, 1, 5, 3};

    selection_sort(vet, 4);

    for (int i = 0; i < 4; i++)
        printf("%d\n", vet[i]);

    return 0;
}