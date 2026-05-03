#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *inserir(no *r, int x)
{
    if (r != NULL)
    {
        if (x > r->chave)
        {
            r->dir = inserir(r->dir, x);
        }
        else if (x < r->chave)
        {
            r->esq = inserir(r->esq, x);
        }
        return r;
    }
    else
    {
        no *novoNo = malloc(sizeof(no));
        novoNo->chave = x;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        return novoNo;
    }
}