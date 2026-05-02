#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    struct celula *esq;
    struct celula *dir;
    int dado;
} Celula;

Celula *remove(Celula *raiz, int x);
Celula *remove_sucessor(Celula *raiz);
Celula *cria_arvore(int x);
Celula *busca(Celula *raiz, int x);
Celula *insere_novo_elemento(Celula *raiz, int dado);
void destroi_arvore_binaria_de_busca(Celula *raiz);

int main()
{

    return 0;
}

//----------------------------------------------------

Celula *remove(Celula *raiz, int x)
{
    if (raiz != NULL)
    {
        if (x > raiz->dado)
        {
            raiz->dir = remove(raiz->dir, x);
        }
        else if (x < raiz->dado)
        {
            raiz->esq = remove(raiz->esq, x);
        }
        else if (raiz->dir == NULL)
        {
            Celula *p = raiz->esq;
            free(raiz);
            return p;
        }
        else if (raiz->esq == NULL)
        {
            Celula *p = raiz->dir;
            free(raiz);
            return p;
        }
        else
        {
            return remove_sucessor(raiz);
        }
    }
}

Celula *remove_sucessor(Celula *raiz)
{
    Celula *pai = raiz;
    Celula *filho = pai->dir;

    while (filho->esq != NULL)
    {
        pai = filho;
        filho = filho->esq;
    }

    raiz->dado = filho->dado;

    if (pai == raiz)
    {
        pai->dir = filho->dir;
    }
    else
    {
        pai->esq = filho->dir;
    }
    free(filho);
}

Celula *cria_arvore(int x)
{
    Celula *novo = malloc(sizeof(Celula));

    novo->dado = x;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

Celula *busca(Celula *raiz, int x)
{

    if (raiz != NULL)
    {
        if (x > raiz->dado)
        {
            return busca(raiz->dir, x);
        }
        else if (x < raiz->dado)
        {
            return busca(raiz->esq, x);
        }
        else
        {
            return raiz;
        }
    }
    else
    {
        return raiz;
    }
}

Celula *insere_novo_elemento(Celula *raiz, int x)
{
    if (raiz != NULL)
    {
        if (x > raiz->dado)
        {
            raiz->dir = insere_novo_elemento(raiz, x);
        }
        else if (x < raiz->dado)
        {
            raiz->esq = insere_novo_elemento(raiz, x);
        }
        else
        {
            return raiz;
        }
    }
    else
    {
        return cria_arvore(x);
    }
}

void destroi_arvore_binaria_de_busca(Celula *raiz)
{
    if (raiz != NULL)
    {
        destroi_arvore_binaria_de_busca(raiz->dir);
        destroi_arvore_binaria_de_busca(raiz->esq);
        free(raiz);
    }
}
