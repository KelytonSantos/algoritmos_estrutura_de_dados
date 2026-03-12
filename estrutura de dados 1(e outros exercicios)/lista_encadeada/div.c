#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{
    celula *atual = l->prox;
    celula *ultimo_impar = l1;
    celula *ultimo_par = l2;

    l1->prox = NULL;
    l2->prox = NULL;

    while (atual != NULL)
    {
        celula *proximo = atual->prox;

        if (atual->dado % 2 != 0)
        {
            ultimo_impar->prox = atual;
            ultimo_impar = atual;
            ultimo_impar->prox = NULL;
        }
        else
        {
            ultimo_par->prox = atual;
            ultimo_par = atual;
            ultimo_par->prox = NULL;
        }

        atual = proximo;
    }

    l->prox = NULL;
}