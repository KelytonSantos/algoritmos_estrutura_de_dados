#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

void remove_sucessor(no *r)
{
    no *pai = r;
    no *filho = pai->esq;

    while (filho->dir != NULL)
    {
        pai = filho;
        filho = filho->dir;
    }
    // faz a troca do maior com o menor
    r->chave = filho->chave;

    if (pai == r)
    {
        pai->esq = filho->esq;
    }
    else
    {
        pai->dir = filho->esq;
    }
    free(filho);
}

no *remover(no *r, int x)
{

    if (r != NULL)
    {
        if (x > r->chave)
        {
            r->dir = remover(r->dir, x);
        }
        else if (x < r->chave)
        {
            r->esq = remover(r->esq, x);
        }
        else if (r->esq == NULL)
        {
            no *p = r->dir;
            free(r);
            return p;
        }
        else if (r->dir == NULL)
        {
            no *p = r->esq;
            free(r);
            return p;
        }
        else
        {
            remove_sucessor(r);
        }
        return r;
    }
    return NULL;
}
