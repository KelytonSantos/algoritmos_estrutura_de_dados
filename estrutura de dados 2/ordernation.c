#include <stdio.h>

/*
    selection sempre pega o menor e troca de posit (nao pode ser estavel)
    insertion vai "aumentando o vetor" e ordenando (pode ser estavel ou nao)
    O(n²)

*/
void troca(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
  0  1  2  3
[2, -1, 3, 4]

[-1, 2, 3, 4]

min = 0
j = 1
2 é maior que -1? sim entao min = j || min = 1
vet[1] troca com vet[0]

min = 1
j = 2
2 é maior que 3? não entao min = 1 e i = 1 (troca ele com ele mesmo)
*/

void selection_sort(int *vet, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {

        int min = i;

        for (int j = i + 1; j < tam; j++)
        {
            if (vet[min] > vet[j])
            {
                min = j;
            }
        }
        troca(&vet[min], &vet[i]);
    }
}

void selection_sort(int *vet, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (vet[min] > vet[j])
            {
                min = j;
            }
        }
        troca(&vet[min], &vet[i]);
    }
}

int main()
{

    return 0;
}