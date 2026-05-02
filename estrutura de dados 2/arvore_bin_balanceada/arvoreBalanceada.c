/*
arvore rubro negra esquerdista

regras:
1) todo nó é vermelho ou preto
2) a raíz é preta
3) as folhas são os nulls e tem cores pretas
4) se um nó é vermelho entao
    * seus filhos são pretos
    * é filho esquerdo
5)para qualquer no, a quantidade de nós pretos a qualquer folha descendente é a mesma
    * se chama altura negra do nó
    * não se conta o nó raiz


    a quantidade de nós é dado sempre por 2^bh -1 onde bh é black heigh (altura negra)

    temos as condições para correção:

    1) ehPreto(r) && ehVermelho(r->esq) && ehVermelho(r->dir): é em relação a subida de cor

    2) ehPreto(r) && ehPreto(r->esq) && ehVermelho(r->dir): rotação a esquerda

    3) ehPreto(r) && ehPreto(r->esq) && ehVermelho(r->esq->esq): rotação a direita de r

    4) ehVermelho(r) && ehPreto(r->esq) && ehVermelho(r->dir): rotação a esquerda de r

*/

#include <stdlib.h>
#include "arvoreBalanceada.h"

int eh_preto(Celula *no)
{
    if (no != NULL)
        return no->cor == PRETO;
    else
        return 1;
}

int eh_vermelho(Celula *no)
{
    if (no != NULL)
        return no->cor == VERMELHO;
    else
        return 0;
}

Celula *insere(Celula *raiz, int x)
{
    raiz = insere_abbrne(raiz, x);
    raiz->cor = PRETO;
    return raiz;
}

Celula *rotacao_a_direita(Celula *raiz)
{
    Celula *a = raiz->esq;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;

    Celula *beta = a->dir;
    a->dir = raiz;
    raiz->esq = beta;
    return a;
}

Celula *rotacao_a_esquerda(Celula *raiz)
{
    Celula *a = raiz->dir;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;

    Celula *beta = a->esq;
    a->esq = raiz;
    raiz->dir = beta;

    return a;
}

void sobe_cor(Celula *raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = raiz->dir->cor = PRETO;
}

Celula *insere_abbrne(Celula *raiz, int x)
{
    if (raiz != NULL)
    {

        if (x < raiz->dado)
        {
            raiz->esq = insere_abbrne(raiz->esq, x);
        }
        else if (x > raiz->dado)
        {
            raiz->dir = insere_abbrne(raiz->dir, x);
        }

        // 1. Rotação à esquerda (vermelho à direita)
        if (eh_vermelho(raiz->dir))
            raiz = rotacao_a_esquerda(raiz);

        // 2. Rotação à direita (dois vermelhos à esquerda)
        if (eh_vermelho(raiz->esq) && eh_vermelho(raiz->esq->esq))
            raiz = rotacao_a_direita(raiz);

        // 3. Sobe cor (ambos filhos vermelhos) - POR ÚLTIMO
        if (eh_vermelho(raiz->esq) && eh_vermelho(raiz->dir))
            sobe_cor(raiz);
    }
    else
    {
        Celula *novo = malloc(sizeof(Celula));
        novo->esq = novo->dir = NULL;
        novo->dado = x;
        novo->cor = VERMELHO;
        return novo;
    }
    return raiz;
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
            return raiz;
    }
    else
        return raiz;
}

static Celula *balanceia(Celula *raiz)
{
    if (eh_vermelho(raiz->dir))
        raiz = rotacao_a_esquerda(raiz);

    if (eh_vermelho(raiz->esq) && eh_vermelho(raiz->esq->esq))
        raiz = rotacao_a_direita(raiz);

    if (eh_vermelho(raiz->esq) && eh_vermelho(raiz->dir))
        sobe_cor(raiz);

    return raiz;
}

static Celula *move_vermelho_a_esquerda(Celula *raiz)
{
    if (raiz == NULL || raiz->dir == NULL)
        return raiz;

    sobe_cor(raiz);

    if (raiz->dir != NULL && eh_vermelho(raiz->dir->esq))
    {
        raiz->dir = rotacao_a_direita(raiz->dir);
        raiz = rotacao_a_esquerda(raiz);
        sobe_cor(raiz);
    }

    return raiz;
}

static Celula *move_vermelho_a_direita(Celula *raiz)
{
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;

    sobe_cor(raiz);

    if (raiz->esq != NULL && eh_vermelho(raiz->esq->esq))
    {
        raiz = rotacao_a_direita(raiz);
        sobe_cor(raiz);
    }

    return raiz;
}

static Celula *menor(Celula *raiz)
{
    while (raiz != NULL && raiz->esq != NULL)
    {
        raiz = raiz->esq;
    }

    return raiz;
}

static Celula *remove_menor(Celula *raiz)
{
    if (raiz->esq == NULL)
    {
        free(raiz);
        return NULL;
    }

    if (!eh_vermelho(raiz->esq) && !eh_vermelho(raiz->esq->esq))
        raiz = move_vermelho_a_esquerda(raiz);

    raiz->esq = remove_menor(raiz->esq);
    return balanceia(raiz);
}

Celula *remover(Celula *raiz, int x)
{
    if (raiz == NULL)
        return NULL;

    if (x < raiz->dado)
    {
        if (raiz->esq != NULL)
        {
            if (!eh_vermelho(raiz->esq) && !eh_vermelho(raiz->esq->esq))
                raiz = move_vermelho_a_esquerda(raiz);

            raiz->esq = remover(raiz->esq, x);
        }
    }
    else
    {
        if (eh_vermelho(raiz->esq))
            raiz = rotacao_a_direita(raiz);

        if (x == raiz->dado && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }

        if (raiz->dir != NULL)
        {
            if (!eh_vermelho(raiz->dir) && !eh_vermelho(raiz->dir->esq))
                raiz = move_vermelho_a_direita(raiz);

            if (x == raiz->dado)
            {
                Celula *m = menor(raiz->dir);
                raiz->dado = m->dado;
                raiz->dir = remove_menor(raiz->dir);
            }
            else
            {
                raiz->dir = remover(raiz->dir, x);
            }
        }
    }

    return balanceia(raiz);
}