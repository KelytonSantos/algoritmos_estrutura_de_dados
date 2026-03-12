#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x)
{
    le = le->prox;

    while (le != NULL && le->dado != x)
    {
        le = le->prox;
    }
    return le;
}

celula *busca_rec(celula *le, int x)
{
    if (le == NULL)
    {
        return NULL;
    }
    if (le->dado == x)
    {
        return le;
    }
    return busca_rec(le->prox, x);
}
