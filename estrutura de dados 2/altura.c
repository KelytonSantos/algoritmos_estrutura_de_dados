#include <stdio.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

int altura(no *r)
{
    if (r == NULL)
        return 0;

    int he = altura(r->esq);
    int hd = altura(r->dir);
    return 1 + (he > hd ? he : hd); // se altura esquerda maior que direita ent retorna he caso contrario retorna hd (a questão aqui é pegar o maior)
}