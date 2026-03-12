#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *new = malloc(sizeof(celula)); // declaring new celula
    new->dado = x;                        // new dado equals x
    new->prox = le->prox;                 // apointing the new prox as the last prox i.e null
    le->prox = new;                       // now, the prox of the begining one is the new one
}

void insere_antes(celula *le, int x, int y)
{
    celula *atual = le;

    while (le->prox != NULL && le->prox->dado != y)
    {
        atual = atual->prox;
    }

    celula *new = malloc(sizeof(celula));
    new->dado = x;
    new->prox = atual->prox;
    atual->prox = new;
}