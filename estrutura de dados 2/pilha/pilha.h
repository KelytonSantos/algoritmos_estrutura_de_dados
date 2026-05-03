#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
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

Pilha *cria_pilha(void);
int pilha_vazia(const Pilha *pilha);
void empilha(Pilha *pilha, no *pnt);
int desempilha(Pilha *pilha, no **pnt);
int topo(const Pilha *pilha, no **pnt);
void destroi_pilha(Pilha *pilha);

#endif
