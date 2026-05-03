#include "pilha.h"

Pilha *cria_pilha(void)
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL)
        return NULL;

    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

int pilha_vazia(const Pilha *pilha)
{
    return pilha == NULL || pilha->tamanho == 0;
}

void empilha(Pilha *pilha, no *pnt)
{
    if (pilha == NULL)
        return;

    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    if (novo == NULL)
        return;

    novo->pnt = pnt;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

int desempilha(Pilha *pilha, no **pnt)
{
    if (pilha_vazia(pilha) || pnt == NULL)
        return 0;

    NoPilha *removido = pilha->topo;
    *pnt = removido->pnt;
    pilha->topo = removido->prox;
    free(removido);
    pilha->tamanho--;
    return 1;
}

int topo(const Pilha *pilha, no **pnt)
{
    if (pilha_vazia(pilha) || pnt == NULL)
        return 0;

    *pnt = pilha->topo->pnt;
    return 1;
}

void destroi_pilha(Pilha *pilha)
{
    if (pilha == NULL)
        return;

    NoPilha *atual = pilha->topo;
    while (atual != NULL)
    {
        NoPilha *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(pilha);
}
