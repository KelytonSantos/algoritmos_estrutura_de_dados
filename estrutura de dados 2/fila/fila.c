#include "fila.h"
#include <stdlib.h>

Fila *cria_fila(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL)
        return NULL;

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

int fila_vazia(const Fila *fila)
{
    return fila == NULL || fila->tamanho == 0;
}

void enfileira(Fila *fila, no *pnt)
{
    if (fila == NULL)
        return;

    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (novo == NULL)
        return;

    novo->pnt = pnt;
    novo->prox = NULL;

    if (fila->fim == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->tamanho++;
}

int desenfileira(Fila *fila, no **pnt)
{
    if (fila_vazia(fila) || pnt == NULL)
        return 0;

    NoFila *removido = fila->inicio;
    *pnt = removido->pnt;
    fila->inicio = removido->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(removido);
    fila->tamanho--;
    return 1;
}

int primeiro(const Fila *fila, no **pnt)
{
    if (fila_vazia(fila) || pnt == NULL)
        return 0;

    *pnt = fila->inicio->pnt;
    return 1;
}

void destroi_fila(Fila *fila)
{
    if (fila == NULL)
        return;

    NoFila *atual = fila->inicio;
    while (atual != NULL)
    {
        NoFila *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(fila);
}
