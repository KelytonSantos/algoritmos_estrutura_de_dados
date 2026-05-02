/*
v[0] é a raiz

se v[i] é um no qualquer temos que:

v[2i+1] é filho esquerdo desse no
v[2i+2] é filho direito desse no
v[(i-1)/2] é seu pai

*/
#include "fp.h"
#include <stdio.h>

FP *cria_fp(int tam)
{
    FP *fp = malloc(sizeof(FP));
    fp->dado = malloc(tam * sizeof(int));
    fp->tamanho = tam;
    fp->n = 0;

    return fp;
}

void insere(FP *f, int x)
{
}

int extrai_maximo(FP *f)
{
    if (f->n > 0)
    {
        int max = f->dado[0];
        f->dado[0] = f->dado[f->n - 1];
        f->n--;
        desce_no_heap(f);
        return max;
    }
}
desce_no_heap(FP *f)
{
    int i = 0, esq = 1, dir = 2, maior_filho;

    while (esq < f->n)
    {
        maior_filho = esq;
        if (dir < f->n && f->dado[dir] > f->dado[esq])
            maior_filho = dir;

        if (f->dado[i] < f->dado[maior_filho])
        {
            troca(&f->dado[i], &f->dado[maior_filho]);
            i = maior_filho;
            esq = 2 * i - 1;
            dir = esq + 1;
        }
        else
            return;
    }
}

void destroi_fp(FP *f)
{
    free(f->dado);
    free(f);
}
