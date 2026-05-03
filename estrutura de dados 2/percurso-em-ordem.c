#include <stdio.h>
#include <stdlib.h>
// #include "pilha/pilha.h"

// gcc -Wall -Wextra -std=c11 percurso-pre-ordem.c pilha/pilha.c -o main
//  cada vez que atualizar raiz enfileira caso esq for null sobe um e entra no dir, se dir for null sobe mais um
typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct no_pilha
{
    no *pnt;
    struct no_pilha *prox;
} NoPilha;

typedef struct
{
    NoPilha *topo;
    size_t tamanho;
} Pilha;

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

void em_ordem(no *raiz)
{
    Pilha *novapilha = cria_pilha();

    while (raiz != NULL || !pilha_vazia(novapilha))
    {
        if (raiz != NULL)
        {
            empilha(novapilha, raiz);
            raiz = raiz->esq;
        }
        else
        {
            desempilha(novapilha, &raiz);
            printf("%d ", raiz->dado);
            raiz = raiz->dir;
        }
    }
}

static no *novo_no(int dado)
{
    no *novo = malloc(sizeof(no));
    if (novo == NULL)
        return NULL;

    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

static void destroi_arvore(no *raiz)
{
    if (raiz == NULL)
        return;

    destroi_arvore(raiz->esq);
    destroi_arvore(raiz->dir);
    free(raiz);
}

/*int main()
{
    no *no1 = novo_no(2);
    no *no2 = novo_no(5);
    no *no3 = novo_no(7);
    no *no4 = novo_no(3);
    no *no5 = novo_no(8);
    no *no6 = novo_no(1);
    no *no7 = novo_no(6);
    no *no8 = novo_no(4);
    no *no9 = novo_no(9);

    if (no1 == NULL || no2 == NULL || no3 == NULL || no4 == NULL || no5 == NULL || no6 == NULL || no7 == NULL || no8 == NULL || no9 == NULL)
    {
        free(no1);
        free(no2);
        free(no3);
        free(no4);
        free(no5);
        free(no6);
        free(no7);
        free(no8);
        free(no9);
        return 1;
    }

    no1->esq = no2;
    no1->dir = no3;

    no2->esq = no4;
    no2->dir = no5;

    no5->esq = no8;

    no3->esq = no6;
    no3->dir = no7;

    no6->esq = no9;

    em_ordem(no1);
    printf("\n");

    destroi_arvore(no1);

    return 0;
}
*/