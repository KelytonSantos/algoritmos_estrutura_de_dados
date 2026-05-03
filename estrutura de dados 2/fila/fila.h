#ifndef FILA_H
#define FILA_H

#include <stddef.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct no_fila
{
    no *pnt;
    struct no_fila *prox;
} NoFila;

typedef struct
{
    NoFila *inicio;
    NoFila *fim;
    size_t tamanho;
} Fila;

Fila *cria_fila(void);
int fila_vazia(const Fila *fila);
void enfileira(Fila *fila, no *pnt);
int desenfileira(Fila *fila, no **pnt);
int primeiro(const Fila *fila, no **pnt);
void destroi_fila(Fila *fila);

#endif
